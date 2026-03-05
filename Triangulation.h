#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include <random>
#include "Edge.h"
#include "Point.h"
#include "Triangle.h"

class Triangulation
{
public:
	Triangulation() = default;
private:
	std::vector<Point> m_points;
	std::vector<Edge> m_edges;
	std::vector<Triangle> m_triangles;
	void generatePoints();
	void triangulate();
};

#endif // TRIANGULATION_H
