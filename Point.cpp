#include "Point.h"

#include <QBrush>
#include <cmath>

Point::Point(double x, double y) :
	m_x(x),
	m_y(y),
	m_image(std::make_unique<QGraphicsEllipseItem>(m_x - diameter / 2, m_y - diameter / 2, diameter, diameter))
{
	m_image->setBrush(QBrush(Qt::black));
}

Point::Point() :
	m_x(0),
	m_y(0)
{}

Point::Point(const Point &point)
{
	m_x = point.m_x;
	m_y = point.m_y;
	m_image = std::make_unique<QGraphicsEllipseItem>(
		point.m_x - diameter / 2, point.m_y - diameter / 2, diameter, diameter);
	m_image->setBrush(QBrush(Qt::black));
}

double Point::distance(const Point& point)
{
	double deltaX = m_x - point.m_x;
	double deltaY = m_y - point.m_y;
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

const double Point::diameter = 10;
