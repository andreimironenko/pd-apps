DESCRIPTION = "Distributed Multi-Threaded  CheckPointing"
HOMEPAGE = "http://dmtcp.sourceforge.net/"
SECTION = "console/misc"
LICENSE = "GPLv2"

DEPENDS = ""
RDEPENDS = "ldd binutils"

inherit autotools 

SRC_URI = "git://github.com/dmtcp/dmtcp.git;protocol=git;branch=${BRANCH} \
		   file://01-dmtcp-arm-build.patch                                \
		   file://dmtcp.conf                                              \
"

SRCREV = "${PV}"
BRANCH = "master"

S = "${WORKDIR}/git"

EXTRA_OECONF = "--disable-test-suite  --disable-openmp" 

do_configure() { 
    autoreconf -i
 	./configure --host=${TARGET_SYS} ${EXTRA_OECONF} --prefix=/usr
}


do_install_append() {
	install -d ${D}${sysconfdir}
	install -m 0755 ${WORKDIR}/dmtcp.conf ${D}${sysconfdir}/
}

FILES_${PN} += "${sysconfdir}/dmtcp.conf"

CONFFILES_${PN} =           "\
   ${sysconfdir}/dmtcp.conf  \
   "
