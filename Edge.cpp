#include "Edge.h"

#include <QPen>

Edge::Edge(Point start, Point end) :
	m_start(start),
	m_end(end),
	m_image(std::make_unique<QGraphicsLineItem>(m_start.x(), m_start.y(), m_end.x(), m_end.y()))
{
	m_image->setPen(QPen(Qt::black, 3));
}

Edge::Edge(const Edge &edge)
{
	m_start = edge.m_start;
	m_end = edge.m_end;
	m_image = std::make_unique<QGraphicsLineItem>(m_start.x(), m_start.y(), m_end.x(), m_end.y());
	m_image->setPen(QPen(Qt::black, 3));
}

bool Edge::intersects(const Edge& edge, Point& point)
{
	QLineF line1 = m_image->line();
	QLineF line2 = edge.m_image->line();
	QPointF* qPoint = new QPointF();
	size_t type = line1.intersects(line2, qPoint);
	if (type != QLineF::BoundedIntersection || qPoint == nullptr)
	{
		delete qPoint;
		return false;
	}
	point = Point(qPoint->x(), qPoint->y());
	delete qPoint;
	return true;
}

Edge &Edge::operator=(const Edge &copy)
{
	if (this != &copy)
	{
		m_start = copy.m_start;
		m_end = copy.m_end;
		m_image = std::make_unique<QGraphicsLineItem>(m_start.x(), m_start.y(), m_end.x(), m_end.y());
		m_image->setPen(QPen(Qt::black, 3));
	}
	return *this;
}
