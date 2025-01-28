#############################################################################
# Makefile for building: Progetto
# Generated by qmake (3.1) (Qt 5.15.13)
# Project:  Progetto.pro
# Template: app
# Command: /usr/lib/qt5/bin/qmake -o Makefile Progetto.pro
#############################################################################

MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I. -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = Progetto1.0.0
DISTDIR = /home/pao/Progetto/.tmp/Progetto1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5Core.so -lGL -lpthread   
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = Interfaccia/BibliotecaMainWindow.cpp \
		Interfaccia/MyToolBar.cpp \
		Interfaccia/SearchInterface.cpp \
		Interfaccia/test_interfaccia.cpp \
		modelloLogicoMedia/Audio.cpp \
		modelloLogicoMedia/Book.cpp \
		modelloLogicoMedia/Duration.cpp \
		modelloLogicoMedia/Film.cpp \
		modelloLogicoMedia/ISBN.cpp \
		modelloLogicoMedia/Magazine.cpp \
		modelloLogicoMedia/Media.cpp \
		modelloLogicoMedia/Multimedia.cpp \
		modelloLogicoMedia/MusicSingle.cpp \
		modelloLogicoMedia/PaperMedia.cpp \
		modelloLogicoMedia/test.cpp \
		modelloLogicoMedia/Video.cpp \
		Visitors/FilterVisitor.cpp \
		Visitors/Query.cpp qrc_resources.cpp \
		moc_BibliotecaMainWindow.cpp \
		moc_MyToolBar.cpp \
		moc_SearchInterface.cpp
OBJECTS       = BibliotecaMainWindow.o \
		MyToolBar.o \
		SearchInterface.o \
		test_interfaccia.o \
		Audio.o \
		Book.o \
		Duration.o \
		Film.o \
		ISBN.o \
		Magazine.o \
		Media.o \
		Multimedia.o \
		MusicSingle.o \
		PaperMedia.o \
		test.o \
		Video.o \
		FilterVisitor.o \
		Query.o \
		qrc_resources.o \
		moc_BibliotecaMainWindow.o \
		moc_MyToolBar.o \
		moc_SearchInterface.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		Progetto.pro Interfaccia/BibliotecaMainWindow.h \
		Interfaccia/MyToolBar.h \
		Interfaccia/SearchInterface.h \
		modelloLogicoMedia/Audio.h \
		modelloLogicoMedia/Book.h \
		modelloLogicoMedia/Duration.h \
		modelloLogicoMedia/Film.h \
		modelloLogicoMedia/ISBN.h \
		modelloLogicoMedia/Magazine.h \
		modelloLogicoMedia/Media.h \
		modelloLogicoMedia/Multimedia.h \
		modelloLogicoMedia/MusicSingle.h \
		modelloLogicoMedia/PaperMedia.h \
		modelloLogicoMedia/Video.h \
		Observers/AbstractMediaObserver.h \
		Visitors/AbstractMediaVisitor.h \
		Visitors/FilterVisitor.h \
		Visitors/Query.h \
		modelloLogicoMedia/Genre/AudioGenre.h \
		modelloLogicoMedia/Genre/BookGenre.h \
		modelloLogicoMedia/Genre/MagazineGenre.h \
		modelloLogicoMedia/Genre/VideoGenre.h Interfaccia/BibliotecaMainWindow.cpp \
		Interfaccia/MyToolBar.cpp \
		Interfaccia/SearchInterface.cpp \
		Interfaccia/test_interfaccia.cpp \
		modelloLogicoMedia/Audio.cpp \
		modelloLogicoMedia/Book.cpp \
		modelloLogicoMedia/Duration.cpp \
		modelloLogicoMedia/Film.cpp \
		modelloLogicoMedia/ISBN.cpp \
		modelloLogicoMedia/Magazine.cpp \
		modelloLogicoMedia/Media.cpp \
		modelloLogicoMedia/Multimedia.cpp \
		modelloLogicoMedia/MusicSingle.cpp \
		modelloLogicoMedia/PaperMedia.cpp \
		modelloLogicoMedia/test.cpp \
		modelloLogicoMedia/Video.cpp \
		Visitors/FilterVisitor.cpp \
		Visitors/Query.cpp
QMAKE_TARGET  = Progetto
DESTDIR       = 
TARGET        = Progetto


first: all
####### Build rules

Progetto:  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Progetto.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		Progetto.pro \
		resources.qrc
	$(QMAKE) -o Makefile Progetto.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xkbcommon_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
Progetto.pro:
resources.qrc:
qmake: FORCE
	@$(QMAKE) -o Makefile Progetto.pro

qmake_all: FORCE


all: Makefile Progetto

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents resources.qrc $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents Interfaccia/BibliotecaMainWindow.h Interfaccia/MyToolBar.h Interfaccia/SearchInterface.h modelloLogicoMedia/Audio.h modelloLogicoMedia/Book.h modelloLogicoMedia/Duration.h modelloLogicoMedia/Film.h modelloLogicoMedia/ISBN.h modelloLogicoMedia/Magazine.h modelloLogicoMedia/Media.h modelloLogicoMedia/Multimedia.h modelloLogicoMedia/MusicSingle.h modelloLogicoMedia/PaperMedia.h modelloLogicoMedia/Video.h Observers/AbstractMediaObserver.h Visitors/AbstractMediaVisitor.h Visitors/FilterVisitor.h Visitors/Query.h modelloLogicoMedia/Genre/AudioGenre.h modelloLogicoMedia/Genre/BookGenre.h modelloLogicoMedia/Genre/MagazineGenre.h modelloLogicoMedia/Genre/VideoGenre.h $(DISTDIR)/
	$(COPY_FILE) --parents Interfaccia/BibliotecaMainWindow.cpp Interfaccia/MyToolBar.cpp Interfaccia/SearchInterface.cpp Interfaccia/test_interfaccia.cpp modelloLogicoMedia/Audio.cpp modelloLogicoMedia/Book.cpp modelloLogicoMedia/Duration.cpp modelloLogicoMedia/Film.cpp modelloLogicoMedia/ISBN.cpp modelloLogicoMedia/Magazine.cpp modelloLogicoMedia/Media.cpp modelloLogicoMedia/Multimedia.cpp modelloLogicoMedia/MusicSingle.cpp modelloLogicoMedia/PaperMedia.cpp modelloLogicoMedia/test.cpp modelloLogicoMedia/Video.cpp Visitors/FilterVisitor.cpp Visitors/Query.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all: qrc_resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resources.cpp
qrc_resources.cpp: resources.qrc \
		/usr/lib/qt5/bin/rcc \
		icons/elimina.png \
		icons/aggiungi.png \
		icons/CD.png \
		icons/book.png \
		icons/magazine.png \
		icons/film.png
	/usr/lib/qt5/bin/rcc -name resources resources.qrc -o qrc_resources.cpp

compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -O2 -Wall -Wextra -dM -E -o moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_BibliotecaMainWindow.cpp moc_MyToolBar.cpp moc_SearchInterface.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_BibliotecaMainWindow.cpp moc_MyToolBar.cpp moc_SearchInterface.cpp
moc_BibliotecaMainWindow.cpp: Interfaccia/BibliotecaMainWindow.h \
		Interfaccia/MyToolBar.h \
		Observers/AbstractMediaObserver.h \
		Interfaccia/SearchInterface.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/pao/Progetto/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/pao/Progetto -I/home/pao/Progetto -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/13 -I/usr/include/x86_64-linux-gnu/c++/13 -I/usr/include/c++/13/backward -I/usr/lib/gcc/x86_64-linux-gnu/13/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include Interfaccia/BibliotecaMainWindow.h -o moc_BibliotecaMainWindow.cpp

moc_MyToolBar.cpp: Interfaccia/MyToolBar.h \
		Observers/AbstractMediaObserver.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/pao/Progetto/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/pao/Progetto -I/home/pao/Progetto -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/13 -I/usr/include/x86_64-linux-gnu/c++/13 -I/usr/include/c++/13/backward -I/usr/lib/gcc/x86_64-linux-gnu/13/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include Interfaccia/MyToolBar.h -o moc_MyToolBar.cpp

moc_SearchInterface.cpp: Interfaccia/SearchInterface.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/pao/Progetto/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/pao/Progetto -I/home/pao/Progetto -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/13 -I/usr/include/x86_64-linux-gnu/c++/13 -I/usr/include/c++/13/backward -I/usr/lib/gcc/x86_64-linux-gnu/13/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include Interfaccia/SearchInterface.h -o moc_SearchInterface.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_predefs_clean compiler_moc_header_clean 

####### Compile

BibliotecaMainWindow.o: Interfaccia/BibliotecaMainWindow.cpp Interfaccia/BibliotecaMainWindow.h \
		Interfaccia/MyToolBar.h \
		Observers/AbstractMediaObserver.h \
		Interfaccia/SearchInterface.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BibliotecaMainWindow.o Interfaccia/BibliotecaMainWindow.cpp

MyToolBar.o: Interfaccia/MyToolBar.cpp Interfaccia/MyToolBar.h \
		Observers/AbstractMediaObserver.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MyToolBar.o Interfaccia/MyToolBar.cpp

SearchInterface.o: Interfaccia/SearchInterface.cpp Interfaccia/SearchInterface.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SearchInterface.o Interfaccia/SearchInterface.cpp

test_interfaccia.o: Interfaccia/test_interfaccia.cpp Interfaccia/BibliotecaMainWindow.h \
		Interfaccia/MyToolBar.h \
		Observers/AbstractMediaObserver.h \
		Interfaccia/SearchInterface.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_interfaccia.o Interfaccia/test_interfaccia.cpp

Audio.o: modelloLogicoMedia/Audio.cpp modelloLogicoMedia/Audio.h \
		modelloLogicoMedia/Multimedia.h \
		modelloLogicoMedia/Media.h \
		modelloLogicoMedia/Duration.h \
		modelloLogicoMedia/Genre/AudioGenre.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Audio.o modelloLogicoMedia/Audio.cpp

Book.o: modelloLogicoMedia/Book.cpp modelloLogicoMedia/Book.h \
		modelloLogicoMedia/PaperMedia.h \
		modelloLogicoMedia/Media.h \
		modelloLogicoMedia/ISBN.h \
		modelloLogicoMedia/Genre/BookGenre.h \
		Visitors/AbstractMediaVisitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Book.o modelloLogicoMedia/Book.cpp

Duration.o: modelloLogicoMedia/Duration.cpp modelloLogicoMedia/Duration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Duration.o modelloLogicoMedia/Duration.cpp

Film.o: modelloLogicoMedia/Film.cpp modelloLogicoMedia/Film.h \
		modelloLogicoMedia/Video.h \
		modelloLogicoMedia/Multimedia.h \
		modelloLogicoMedia/Media.h \
		modelloLogicoMedia/Duration.h \
		modelloLogicoMedia/Genre/VideoGenre.h \
		Visitors/AbstractMediaVisitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Film.o modelloLogicoMedia/Film.cpp

ISBN.o: modelloLogicoMedia/ISBN.cpp modelloLogicoMedia/ISBN.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ISBN.o modelloLogicoMedia/ISBN.cpp

Magazine.o: modelloLogicoMedia/Magazine.cpp modelloLogicoMedia/Magazine.h \
		modelloLogicoMedia/PaperMedia.h \
		modelloLogicoMedia/Media.h \
		modelloLogicoMedia/Genre/MagazineGenre.h \
		Visitors/AbstractMediaVisitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Magazine.o modelloLogicoMedia/Magazine.cpp

Media.o: modelloLogicoMedia/Media.cpp modelloLogicoMedia/Media.h \
		Observers/AbstractMediaObserver.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Media.o modelloLogicoMedia/Media.cpp

Multimedia.o: modelloLogicoMedia/Multimedia.cpp modelloLogicoMedia/Multimedia.h \
		modelloLogicoMedia/Media.h \
		modelloLogicoMedia/Duration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Multimedia.o modelloLogicoMedia/Multimedia.cpp

MusicSingle.o: modelloLogicoMedia/MusicSingle.cpp modelloLogicoMedia/MusicSingle.h \
		modelloLogicoMedia/Audio.h \
		modelloLogicoMedia/Multimedia.h \
		modelloLogicoMedia/Media.h \
		modelloLogicoMedia/Duration.h \
		modelloLogicoMedia/Genre/AudioGenre.h \
		Visitors/AbstractMediaVisitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MusicSingle.o modelloLogicoMedia/MusicSingle.cpp

PaperMedia.o: modelloLogicoMedia/PaperMedia.cpp modelloLogicoMedia/PaperMedia.h \
		modelloLogicoMedia/Media.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PaperMedia.o modelloLogicoMedia/PaperMedia.cpp

test.o: modelloLogicoMedia/test.cpp modelloLogicoMedia/Book.h \
		modelloLogicoMedia/PaperMedia.h \
		modelloLogicoMedia/Media.h \
		modelloLogicoMedia/ISBN.h \
		modelloLogicoMedia/Genre/BookGenre.h \
		modelloLogicoMedia/Magazine.h \
		modelloLogicoMedia/Genre/MagazineGenre.h \
		modelloLogicoMedia/Film.h \
		modelloLogicoMedia/Video.h \
		modelloLogicoMedia/Multimedia.h \
		modelloLogicoMedia/Duration.h \
		modelloLogicoMedia/Genre/VideoGenre.h \
		Visitors/Query.h \
		Visitors/FilterVisitor.h \
		Visitors/AbstractMediaVisitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test.o modelloLogicoMedia/test.cpp

Video.o: modelloLogicoMedia/Video.cpp modelloLogicoMedia/Video.h \
		modelloLogicoMedia/Multimedia.h \
		modelloLogicoMedia/Media.h \
		modelloLogicoMedia/Duration.h \
		modelloLogicoMedia/Genre/VideoGenre.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Video.o modelloLogicoMedia/Video.cpp

FilterVisitor.o: Visitors/FilterVisitor.cpp modelloLogicoMedia/Book.h \
		modelloLogicoMedia/PaperMedia.h \
		modelloLogicoMedia/Media.h \
		modelloLogicoMedia/ISBN.h \
		modelloLogicoMedia/Genre/BookGenre.h \
		modelloLogicoMedia/Magazine.h \
		modelloLogicoMedia/Genre/MagazineGenre.h \
		modelloLogicoMedia/MusicSingle.h \
		modelloLogicoMedia/Audio.h \
		modelloLogicoMedia/Multimedia.h \
		modelloLogicoMedia/Duration.h \
		modelloLogicoMedia/Genre/AudioGenre.h \
		modelloLogicoMedia/Film.h \
		modelloLogicoMedia/Video.h \
		modelloLogicoMedia/Genre/VideoGenre.h \
		Visitors/FilterVisitor.h \
		Visitors/AbstractMediaVisitor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o FilterVisitor.o Visitors/FilterVisitor.cpp

Query.o: Visitors/Query.cpp Visitors/Query.h \
		modelloLogicoMedia/Book.h \
		modelloLogicoMedia/PaperMedia.h \
		modelloLogicoMedia/Media.h \
		modelloLogicoMedia/ISBN.h \
		modelloLogicoMedia/Genre/BookGenre.h \
		modelloLogicoMedia/Magazine.h \
		modelloLogicoMedia/Genre/MagazineGenre.h \
		modelloLogicoMedia/MusicSingle.h \
		modelloLogicoMedia/Audio.h \
		modelloLogicoMedia/Multimedia.h \
		modelloLogicoMedia/Duration.h \
		modelloLogicoMedia/Genre/AudioGenre.h \
		modelloLogicoMedia/Film.h \
		modelloLogicoMedia/Video.h \
		modelloLogicoMedia/Genre/VideoGenre.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Query.o Visitors/Query.cpp

qrc_resources.o: qrc_resources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_resources.o qrc_resources.cpp

moc_BibliotecaMainWindow.o: moc_BibliotecaMainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_BibliotecaMainWindow.o moc_BibliotecaMainWindow.cpp

moc_MyToolBar.o: moc_MyToolBar.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MyToolBar.o moc_MyToolBar.cpp

moc_SearchInterface.o: moc_SearchInterface.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_SearchInterface.o moc_SearchInterface.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

