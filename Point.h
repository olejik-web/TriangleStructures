#ifndef POINT_H
#define POINT_H

#include <QGraphicsEllipseItem>


class Point
{
public:
	static const double diameter;
	Point(double x, double y);
	Point();
	Point(const Point& point);
	QGraphicsEllipseItem* image();
	double x();
	double y();
	double distance(const Point& point);
private:
	double m_x, m_y;
	std::unique_ptr<QGraphicsEllipseItem> m_image;
};

inline QGraphicsEllipseItem* Point::image()
{
	return m_image.get();
}

inline double Point::x()
{
	return m_x;
}

inline double Point::y()
{
	return m_y;
}

#endif // POINT_H
