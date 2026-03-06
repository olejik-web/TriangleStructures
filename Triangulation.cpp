#include "Triangulation.h"

Triangulation::Triangulation()
{
    generatePoints();
    triangulate();
}

Triangle *Triangulation::triangle(size_t index)
{
    return &m_triangles[index];
}

Point* Triangulation::point(const QPointF &pos)
{
    for (size_t i = 0; i < m_points.size(); i++)
    {
        if (m_points[i].image()->contains(pos))
            return &m_points[i];
    }
    return nullptr;
}

Edge* Triangulation::edge(const QPointF &pos)
{
    for (size_t i = 0; i < m_edges.size(); i++)
    {
        if (m_edges[i].image()->contains(pos))
            return &m_edges[i];
    }
    return nullptr;
}

Triangle *Triangulation::triangle(const QPointF &pos)
{
    for (size_t i = 0; i < m_triangles.size(); i++)
    {
        if (m_triangles[i].image()->contains(pos))
            return &m_triangles[i];
    }
    return nullptr;
}

void Triangulation::drop()
{
    for (auto& point : m_points)
        point.drop();
    for (auto& edge : m_edges)
        edge.drop();
    for (auto& triangle : m_triangles)
        triangle.drop();
}

void Triangulation::selectNodesWithNeighbours(const Point& point)
{
    for (size_t i = 0; i < m_points.size(); i++)
    {
        if (m_points[i] == point)
            m_points[i].select();
    }
    for (size_t i = 0; i < m_edges.size(); i++)
    {
        if (*m_edges[i].start() == point)
            m_edges[i].end()->select(true);
        if (*m_edges[i].end() == point)
            m_edges[i].start()->select(true);
    }
}

void Triangulation::generatePoints()
{
	std::random_device rd;
	std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-m_width, m_width);
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
}

void Triangulation::triangulate()
{
    for (size_t i = 0; i < m_points.size(); i++)
	{
        for (size_t j = i + 1; j < m_points.size(); j++)
            m_edges.push_back(Edge(&m_points[i], &m_points[j]));
	}
	sort(m_edges.begin(), m_edges.end(), [](Edge a, Edge b) {return a.length() < b.length();});
	auto left = m_edges.begin() + 1;
	while (left != m_edges.end())
	{
		auto right = left - 1;
		while (right != m_edges.begin() - 1)
		{
			Point point;
			bool intersection = right->intersects(*left, point);
			if (intersection && std::find(m_points.begin(), m_points.end(), point) == m_points.end())
			{
				m_edges.erase(left);
				left--;
				break;
			}
			right--;
		}
		left++;
	}
    m_triangles.push_back(Triangle(&m_points[0], &m_points[1], &m_points[2]));
}
