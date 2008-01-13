#!/bin/sh
#
# $Id$

# vi:set ts=2 sw=2 et ai:
#
# Copyright (c) 2008 Jannis Pohlmann <jannis@xfce.org>
#

# Check if xdt-autogen is installed
(type xdt-autogen) >/dev/null 2>&1 || {
  cat >&2 <<EOF
autogen.sh: You don't seem to have the Xfce development tools installed on
            your system, which are required to build this software.
            Please install the xfce4-dev-tools package first, it is available
            from http://www.xfce.org/.
EOF
  exit 1
}

# Verify that po/LINGUAS is present
(test -f po/LINGUAS) >/dev/null 2>&1 || {
  cat >&2 <<EOF
autogen.sh: The file po/LINGUAS could not be found. Please check your snapshot
            or try to checkout again.
EOF
  exit 1
}

# Substitute revision and linguas
linguas=`sed -e '/^#/d' po/LINGUAS`
sed -e "s/@LINGUAS@/${linguas}/g" < "configure.in.in" > "configure.in"

exec xdt-autogen $@
