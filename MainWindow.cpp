#include "Edge.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QGraphicsEllipseItem>
#include <random>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->graphicsView->setScene(&m_scene);
}

MainWindow::~MainWindow()
{
	delete ui;
}
