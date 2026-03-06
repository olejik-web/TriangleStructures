#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include "StructureType.h"
#include <random>
#include "Edge.h"
#include "Point.h"
#include "Triangle.h"

class Triangulation
{
public:
    Triangulation();
    Point* point(size_t index);
    Edge* edge(size_t index);
    Triangle* triangle(size_t index);
    Point* point(const QPointF& pos);
    Edge* edge(const QPointF& pos);
    Triangle* triangle(const QPointF& pos);
    size_t pointsCount() const;
    size_t edgesCount() const;
    size_t trianglesCount() const;
    void drop();
    void selectNodesWithNeighbours(const Point& point);

private:
	std::vector<Point> m_points;
	std::vector<Edge> m_edges;
	std::vector<Triangle> m_triangles;
    int m_width{290};
	void generatePoints();
	void triangulate();
};

inline size_t Triangulation::trianglesCount() const
{
    return m_triangles.size();
}

inline size_t Triangulation::pointsCount() const
{
    return m_points.size();
}

inline size_t Triangulation::edgesCount() const
{
    return m_edges.size();
}

inline Point* Triangulation::point(size_t index)
{
    return &m_points[index];
}

inline Edge* Triangulation::edge(size_t index)
{
    return &m_edges[index];
}

#endif // TRIANGULATION_H
