#include "TriangulateScene.h"
#include <QGraphicsSceneMouseEvent>

TriangulateScene::TriangulateScene(QObject *parent) :
    QGraphicsScene{parent}
{

    for (size_t i = 0; i < m_triangulation.trianglesCount(); i++)
        addItem(m_triangulation.triangle(i)->image());
    for (size_t i = 0; i < m_triangulation.edgesCount(); i++)
        addItem(m_triangulation.edge(i)->image());
    for (size_t i = 0; i < m_triangulation.pointsCount(); i++)
        addItem(m_triangulation.point(i)->image());
}


void TriangulateScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        qInfo() << "Scene mouse press at:" << event->scenePos();
        Point* point = m_triangulation.point(event->scenePos());
        if (point != nullptr)
        {
            m_triangulation.drop();
            selectStructure(*point);
            return;
        }
        Edge* edge = m_triangulation.edge(event->scenePos());
        if (edge != nullptr)
        {
            m_triangulation.drop();
            // selectStructure(*edge);
            edge->select();
            return;
        }
        Triangle* triangle = m_triangulation.triangle(event->scenePos());
        if (triangle != nullptr)
        {
            m_triangulation.drop();
            triangle->select();
            return;
        }
    }
    else
        QGraphicsScene::mousePressEvent(event);
}

void TriangulateScene::selectStructure(const Point& point)
{
    switch(m_structureType)
    {
    case NodesWithNeighbours:
        m_triangulation.selectNodesWithNeighbours(point);
    }
}

void TriangulateScene::selectStructure(const Edge &edge)
{
    // switch(m_structureType)
    // {

    // }
}

void TriangulateScene::selectStructure(const Triangle &triangle)
{
    // switch(m_structureType)
    // {
    // }
}
