QT = core gui widgets

CONFIG += c++17 cmdline



SOURCES += \
	Edge.cpp \
	MainWindow.cpp \
	Point.cpp \
	Triangle.cpp \
	TriangleStructures.cpp
	Point.cpp
	Edge.cpp
	Triangle.cpp

HEADERS += \
	Edge.h \
	MainWindow.h \
	Point.h \
	Point.h \
	Triangle.h
	Edge.h
	Triangle.h

FORMS += \
	MainWindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
