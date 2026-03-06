#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include <QGraphicsPolygonItem>
#include <QPolygonF>


class Triangle
{
public:
    Triangle(Point* first, Point* second, Point* third);
    Triangle() = default;
    Triangle(const Triangle& copy);
    Triangle& operator=(const Triangle& copy);
    ~Triangle() = default;
    QGraphicsPolygonItem* image();
    Point* first();
    Point* second();
    Point* third();
    void drop();
    void select();
private:
    Point* m_first;
    Point* m_second;
    Point* m_third;
    std::unique_ptr<QGraphicsPolygonItem> m_image;
};

inline QGraphicsPolygonItem* Triangle::image()
{
    return m_image.get();
}

inline Point* Triangle::first()
{
    return m_first;
}

inline Point* Triangle::second()
{
    return m_second;
}

inline Point* Triangle::third()
{
    return m_third;
}

#endif // TRIANGLE_H
