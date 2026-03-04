#include "Edge.h"

#include <QPen>

Edge::Edge(Point start, Point end) :
	m_start(start),
	m_end(end),
	m_image(std::make_unique<QGraphicsLineItem>(m_start.x(), m_start.y(), m_end.x(), m_end.y()))
{
	m_image->setPen(QPen(Qt::black, 3));
}

Edge::Edge()
{}
