######################################################################
# Automatically generated by qmake (3.1) Wed Feb 12 12:30:25 2025
######################################################################

TEMPLATE = app
TARGET = Progetto
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT+=widgets
# Input
HEADERS += Interfaccia/AudioEditView.h \
           Interfaccia/BibliotecaMainWindow.h \
           Interfaccia/BookEditView.h \
           Interfaccia/DetailView.h \
           Interfaccia/DurationSlider.h \
           Interfaccia/EditView.h \
           Interfaccia/FilmEditView.h \
           Interfaccia/ListWidgetMedia.h \
           Interfaccia/ListWidgetMediaItem.h \
           Interfaccia/MagazineEditView.h \
           Interfaccia/MainView.h \
           Interfaccia/MultimediaEditView.h \
           Interfaccia/MusicSingleEditView.h \
           Interfaccia/MyToolBar.h \
           Interfaccia/PaperMediaEditView.h \
           Interfaccia/SearchInterface.h \
           Interfaccia/SearchListWidgetMedia.h \
           Interfaccia/VideoEditView.h \
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
           Visitors/DetailVisitor.h \
           Visitors/EditVisitor.h \
           Visitors/JsonVisitor.h \
           Visitors/Query.h \
           Visitors/WidgetVisitor.h \
           modelloLogicoMedia/Genre/AudioGenre.h \
           modelloLogicoMedia/Genre/BookGenre.h \
           modelloLogicoMedia/Genre/MagazineGenre.h \
           modelloLogicoMedia/Genre/VideoGenre.h
SOURCES += main.cpp \
           Interfaccia/AudioEditView.cpp \
           Interfaccia/BibliotecaMainWindow.cpp \
           Interfaccia/BookEditView.cpp \
           Interfaccia/DetailView.cpp \
           Interfaccia/DurationSlider.cpp \
           Interfaccia/EditView.cpp \
           Interfaccia/FilmEditView.cpp \
           Interfaccia/ListWidgetMedia.cpp \
           Interfaccia/ListWidgetMediaItem.cpp \
           Interfaccia/MagazineEditView.cpp \
           Interfaccia/MainView.cpp \
           Interfaccia/MultimediaEditView.cpp \
           Interfaccia/MusicSingleEditView.cpp \
           Interfaccia/MyToolBar.cpp \
           Interfaccia/PaperMediaEditView.cpp \
           Interfaccia/SearchInterface.cpp \
           Interfaccia/SearchListWidgetMedia.cpp \
           Interfaccia/VideoEditView.cpp \
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
           modelloLogicoMedia/Video.cpp \
           Visitors/DetailVisitor.cpp \
           Visitors/EditVisitor.cpp \
           Visitors/JsonVisitor.cpp \
           Visitors/Query.cpp \
           Visitors/WidgetVisitor.cpp
RESOURCES += resources.qrc
