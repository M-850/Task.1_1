include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt
INCLUDEPATH += F:\Test
HEADERS += \
        ../../../Test/IKeypad.h \
        ../../../Test/ILatch.h \
        ../../../Test/lockcontroller.h \
        tst_test_1.h

SOURCES += \
        ../../../Test/lockcontroller.cpp \
        main.cpp
