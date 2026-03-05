#ifndef EDGE_H
#define EDGE_H
#include "Point.h"

class Edge
{
public:
	Edge(Point start, Point end);
	Edge() = default;
	Edge(const Edge& edge);
	Edge& operator=(const Edge& copy);
	~Edge() = default;
	bool intersects(const Edge& edge, Point& point);
	const Point& start();
	const Point& end();
	QGraphicsLineItem* image();
	double length() const;
private:
	Point m_start, m_end;
	std::unique_ptr<QGraphicsLineItem> m_image;
};

inline double Edge::length() const
{
	return m_start.distance(m_end);
}

inline const Point& Edge::start()
{
	return m_start;
}

inline const Point& Edge::end()
{
	return m_end;
}

inline QGraphicsLineItem* Edge::image()
{
	return m_image.get();
}

#endif // EDGE_H
