TEMPLATE = app
TARGET =  lightseek_qt
DEPENDPATH += .
INCLUDEPATH += include

# Input
HEADERS += \
    include/MainWindow.h \
    include/WorldWidget.h

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/WorldWidget.cpp

# Generation
MOC_DIR = moc
UI_DIR = uic
OBJECTS_DIR = obj