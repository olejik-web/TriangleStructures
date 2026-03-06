QT = core gui widgets

CONFIG += c++17 cmdline

CONFIG(debug, debug|release) {
	QMAKE_CXXFLAGS += -fsanitize=address -fno-omit-frame-pointer
	QMAKE_CFLAGS += -fsanitize=address -fno-omit-frame-pointer
	QMAKE_LFLAGS += -fsanitize=address

	QMAKE_CXXFLAGS += -g -O1
	QMAKE_CFLAGS += -g -O1

	DEFINES += USE_ASAN
}

SOURCES += \
	Edge.cpp \
	MainWindow.cpp \
	Point.cpp \
	Triangle.cpp \
	TriangleStructures.cpp \
	TriangulateScene.cpp \
	Triangulation.cpp
	Point.cpp
	Edge.cpp
	Triangle.cpp

HEADERS += \
	Edge.h \
	MainWindow.h \
	Point.h \
	Point.h \
	StructureType.h \
	Triangle.h \
	TriangulateScene.h \
	Triangulation.h
	Edge.h
	Triangle.h

FORMS += \
	MainWindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
