DESCRIPTION = "CUnit is lightweight C-based testframework"
HOMEPAGE = "http://cunit.sourceforge.net"
SECTION = "console/misc"
LICENSE = "GPLv2"

DEPENDS = "ncurses"

inherit autotools 

SRC_URI = "git://${GITSERVER}/oss/cunit.git;protocol=git;branch=${BRANCH}"

SRCREV = "${PV}"
BRANCH = "master"

S = "${WORKDIR}/git"

EXTRA_OECONF = "--enable-silent-rules"
EXTRA_OECONF += "--enable-automated --enable-basic"
EXTRA_OECONF += "--enable-console --enable-curses"
EXTRA_OECONF += "--disable-examples --disable-test"
EXTRA_OECONF += "--enable-debug"  