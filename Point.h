#ifndef POINT_H
#define POINT_H

#include <QGraphicsEllipseItem>


class Point
{
public:
	static const double diameter;
	Point(double x, double y);
	Point() = default;
	Point(const Point& copy);
	Point& operator=(const Point& copy);
	~Point() = default;
	QGraphicsEllipseItem* image();
	double x() const;
	double y() const;
	double distance(const Point& point) const;
	bool operator==(const Point& other) const;
    void drop();
    void select(bool isNeighbour = false);
    QPointF center() const;
private:
	double m_x{0}, m_y{0};
	std::unique_ptr<QGraphicsEllipseItem> m_image;
};

inline bool Point::operator==(const Point& other) const
{
	return abs(m_x - other.m_x) < 1e-5 && abs(m_y - other.m_y) < 1e-5;
}

inline QGraphicsEllipseItem* Point::image()
{
	return m_image.get();
}

inline double Point::x() const
{
	return m_x;
}

inline double Point::y() const
{
	return m_y;
}

inline QPointF Point::center() const
{
    return QPointF(m_x, m_y);
}

#endif // POINT_H
