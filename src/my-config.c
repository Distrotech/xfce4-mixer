#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <gtk/gtk.h>
#include <libxfce4util/libxfce4util.h>

#include "my-config.h"

#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif
#ifdef SYS_TYPES_H
#include <sys/types.h>
#endif

#define USE_LOCKING 1 /* change that when nfs makes trouble */
/*
TODO: 
<benny> quite simple: 1) parse the input file (don't trust on g_file_test() or access() results, check the fopen result to see if the file exists)...
<benny> 2) fopen(target + ".tmp." + getpid(), "w")
<benny> 3) write the new config
<benny> 4) fclose(target)
<benny> (that is, whats returned from fopen above)
<benny> 5) rename(target + ".tmp." + getpid(), target)
<benny> (check the result of rename and issue a warning)
<benny> 6) unlink(target + ".tmp." + getpid()) if rename failed
<benny> 7) unlink(input) ... you could also do this right after the fopen(input, "r") to reduce the chance of a race cond

<benny> well, xfce_rc_* does that automagically... if you decide that you don't want to use xfce_rc_*, then you're stuck to do it yourself :-P
*/

#if 0
static gchar *
get_tmp_file_name()
{
	gchar *nfilename;
	pid_t	pid;
	pid = getpid();
	nfilename = g_strdup_printf("%s.tmp.%lu", origfilename, (gulong) pid);
	return nfilename;
}


static int 
create_tmp_file(gchar const *origfilename)
{
	int	handle;
	gchar *nfilename;
	if (!nfilename) {
		errno = ENOENT;
	}
	
	handle = open(nfilename, O_WRONLY|O_CREAT, 0644);
	g_free (nfilename);
	return handle;
}

static void
rename_tmp_file()
{
}

#endif

static void 
migrate_errno_print(gchar const *oldpath, gchar const *newpath, int errno, gboolean newfile_culprit)
{
	char tmp[2049];
	gchar *whichfile;
	if (strerror_r (errno, tmp, sizeof(tmp)) != -1) {
		if (!newfile_culprit)
			whichfile = "old file";
		else
			whichfile = "new file";
			
		g_warning("could not migrate \"%s\" to \"%s\" because: %s (%s)", oldpath, newpath, tmp, whichfile);
	} else {
		g_warning("could not migrate \"%s\" to \"%s\" because something went wrong (%s)", oldpath, newpath, whichfile);
	}
}

static void
copy_from_old_config(gchar const *oldpath, gchar const *filename)
{
	gchar *abspath;
	int newfile;
	int oldfile;
	char buf[20000];
	ssize_t rcnt;
	ssize_t wcnt;

	if (!oldpath)
		return; /* no old file: nothing to migrate from */

	abspath = xfce_resource_save_location (XFCE_RESOURCE_CONFIG, filename, TRUE);
			
	if (!abspath) /* no new file: nothing to migrate to */
		return;
		
	oldfile = -1;
	newfile = -1;
	
	oldfile = open(oldpath, O_RDONLY);
	if (oldfile == -1) { /* no old file: nothing to migrate from */
		migrate_errno_print (oldpath, abspath, errno, FALSE);
		goto endme;
	}
	
#ifdef USE_LOCKING
	lockf(oldfile, F_LOCK, 0);
#endif
	newfile = open(abspath, O_CREAT|O_WRONLY, 0644);
	if (newfile == -1) { /* new file couldnt be created, probably already exists */
		migrate_errno_print (oldpath, abspath, errno, TRUE);
		goto endme;
	}
#ifdef USE_LOCKING
	lockf(newfile, F_LOCK, 0);
#endif
	/* at this point both files are open and to be copied */
	while ((rcnt = read (oldfile, buf, sizeof(buf))) > 0) {
		wcnt = write (newfile, buf, rcnt);
		if (wcnt <= 0) { /* something went wrong */
			if (wcnt < 0) /* normal error */
				migrate_errno_print (oldpath, abspath, errno, TRUE);
			else /* impossible error */
				migrate_errno_print (oldpath, abspath, EIO, TRUE);

			close (newfile); /* -1: dont care since its being deleted anyways */
			newfile = -1;
			unlink (abspath);
			goto endme;
		}
	}
	
	if (rcnt < 0) {
		migrate_errno_print (oldpath, abspath, errno, FALSE);
		goto endme;
	}
	
endme:
	if (newfile != -1) { /* open: close down */
		flock(newfile, LOCK_UN);
		if (close(newfile) == -1) { /* didnt work, something went wrong when flushing, probably, so revert. */
			migrate_errno_print (oldpath, abspath, errno, TRUE);
			
			newfile = -1;
			unlink (abspath);
		}
	}
		
	if (oldfile != -1) {
		flock(oldfile, LOCK_UN);
		close(oldfile); /* -1: dont care since we already read everything */
	}
		
	g_free (abspath);
}

gchar *
get_config_path(gchar const *relpath, ConfigAction save)
{
	gchar *filename;
	gchar *abspath;
	abspath = NULL;
	if (!relpath)
		return NULL;
	
	filename = g_build_filename (MIXER_CONFIG_SUBPATH, relpath, NULL);
	
	if (filename) {
		if (save)
			abspath = xfce_resource_save_location (XFCE_RESOURCE_CONFIG, filename, TRUE);
		else {
			abspath = xfce_resource_lookup (XFCE_RESOURCE_CONFIG, filename);
			if (!abspath) {
				/* look for config in old location */
				abspath = xfce_get_userfile ("xfce4-mixer", relpath, NULL);
				if (abspath && access (abspath, R_OK)) {
					copy_from_old_config (abspath, filename);
					g_free (abspath);
					abspath = xfce_resource_lookup (XFCE_RESOURCE_CONFIG, filename);
				}
			}
		}
	
		g_free (filename);
	}
	return abspath;
}

