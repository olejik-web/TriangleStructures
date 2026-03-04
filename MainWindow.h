#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Edge.h"
#include "Point.h"
#include <QGraphicsScene>
#include <QMainWindow>
#include <vector>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow *ui;
	QGraphicsScene m_scene;
	std::vector<Point> m_points;
	std::vector<Edge> m_edges;
	void generatePoints();
	void triangulate();
};

#endif // MAINWINDOW_H
