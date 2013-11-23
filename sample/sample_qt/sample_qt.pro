TEMPLATE = app
TARGET =  lightseek_qt
DEPENDPATH += .
INCLUDEPATH += include

# Input
HEADERS += \
    include/MainWindow.h

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp

# Generation
MOC_DIR = moc
UI_DIR = uic
OBJECTS_DIR = obj