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

Point::Point(const Point& copy)
{
	m_x = copy.m_x;
	m_y = copy.m_y;
	m_image = std::make_unique<QGraphicsEllipseItem>(m_x - diameter / 2, m_y - diameter / 2, diameter, diameter);
	m_image->setBrush(QBrush(Qt::black));
}

Point &Point::operator=(const Point &copy)
{
	if (&copy != this)
	{
		m_x = copy.m_x;
		m_y = copy.m_y;
		m_image = std::make_unique<QGraphicsEllipseItem>(m_x - diameter / 2, m_y - diameter / 2, diameter, diameter);
		m_image->setBrush(QBrush(Qt::black));
	}
	return *this;
}

double Point::distance(const Point& point) const
{
	double deltaX = m_x - point.m_x;
	double deltaY = m_y - point.m_y;
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

const double Point::diameter = 10;
