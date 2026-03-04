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
	generatePoints();
	triangulate();
	ui->graphicsView->setScene(&m_scene);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::generatePoints()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(-290, 290);
	int count = 40;
	for (int i = 0; i < count; i++)
	{
		bool near = true;
		double x;
		double y;
		while (near)
		{
			x = dist(gen);
			y = dist(gen);
			near = false;
			for (auto& point : m_points)
				near = near || (point.distance(Point(x, y)) < 2 * Point::diameter);
		}
		m_points.push_back(Point(x, y));
	}
	for (int i = 0; i < count; i++)
		m_scene.addItem(m_points[i].image());
}

void MainWindow::triangulate()
{
	for (int i = 0; i < m_points.size(); i++)
	{
		for (int j = i + 1; j < m_points.size(); j++)
			m_edges.push_back(Edge(m_points[i], m_points[j]));
	}
	auto it = m_edges.begin() + 1;
	while (it != m_edges.end())
	{
		if ()
	}
	for (int i = 0; i < m_points.size(); )
	m_edges.push_back(Edge(m_points[0], m_points[1]));
	m_scene.addItem(m_edges[0].image());
}
