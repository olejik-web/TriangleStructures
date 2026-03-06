#ifndef EDGE_H
#define EDGE_H
#include "Point.h"

class Edge
{
public:
    Edge(Point* start, Point* end);
	Edge() = default;
	Edge(const Edge& edge);
	Edge& operator=(const Edge& copy);
	~Edge() = default;
	bool intersects(const Edge& edge, Point& point);
    Point* start();
    Point* end();
	QGraphicsLineItem* image();
	double length() const;
    void drop();
    void select();
private:
    Point* m_start{nullptr};
    Point* m_end{nullptr};
    std::unique_ptr<QGraphicsLineItem> m_image;
};

inline double Edge::length() const
{
    return m_start->distance(*m_end);
}

inline Point* Edge::start()
{
	return m_start;
}

inline Point* Edge::end()
{
	return m_end;
}

inline QGraphicsLineItem* Edge::image()
{
	return m_image.get();
}

#endif // EDGE_H
