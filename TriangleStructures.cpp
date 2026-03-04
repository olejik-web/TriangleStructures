#include "MainWindow.h"
#include <cstdlib>
#include <unistd.h>
#include <QtWidgets/QApplication>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWindow mainWindow;
	mainWindow.show();
	return app.exec();
}
