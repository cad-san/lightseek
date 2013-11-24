TEMPLATE = app
TARGET =  lightseek_qt

ROOT_DIR = ../..

DEPENDPATH += .
INCLUDEPATH +=  include \
                $${ROOT_DIR}/include/agent \
                $${ROOT_DIR}/include/device \
                $${ROOT_DIR}/include/world \
                $${ROOT_DIR}/subsumption/include/agent \
                $${ROOT_DIR}/subsumption/include/environment \
                $${ROOT_DIR}/subsumption/include/util

LIBS += -L$${ROOT_DIR}/lib \
        -L$${ROOT_DIR}/subsumption/lib \
        -llightseek -lsubsumption -lboost_thread-mt -lboost_system-mt

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