#include "Triangle.h"

#include <QBrush>
#include <QPen>

Triangle::Triangle(Point *first, Point *second, Point *third) :
    m_first(first),
    m_second(second),
    m_third(third),
    m_image(std::make_unique<QGraphicsPolygonItem>(QPolygonF({m_first->center(),
        m_second->center(), m_third->center()})))
{
    drop();
}

Triangle::Triangle(const Triangle& copy)
{
    m_first = copy.m_first;
    m_second = copy.m_second;
    m_third = copy.m_third;
    m_image = std::make_unique<QGraphicsPolygonItem>(
        QPolygonF({copy.m_first->center(), copy.m_second->center(),
        copy.m_third->center()}));
    drop();
}

Triangle& Triangle::operator=(const Triangle& copy)
{
    if (this != &copy)
    {
        m_first = copy.m_first;
        m_second = copy.m_second;
        m_third = copy.m_third;
        m_image = std::make_unique<QGraphicsPolygonItem>(
            QPolygonF({copy.m_first->center(), copy.m_second->center(),
            copy.m_third->center()}));
        drop();
    }
    return *this;
}

void Triangle::drop()
{
    m_image->setBrush(QBrush(Qt::magenta));
    m_image->setPen(QPen(Qt::NoPen));
}

void Triangle::select()
{
    m_image->setBrush(QBrush(Qt::cyan));
}
