#include "Triangulation.h"

void Triangulation::generatePoints()
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
}

void Triangulation::triangulate()
{
	for (int i = 0; i < m_points.size(); i++)
	{
		for (int j = i + 1; j < m_points.size(); j++)
			m_edges.push_back(Edge(m_points[i], m_points[j]));
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
}
