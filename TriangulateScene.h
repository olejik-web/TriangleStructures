#ifndef TRIANGULATESCENE_H
#define TRIANGULATESCENE_H

#include "Triangulation.h"
#include <QGraphicsScene>
#include <QObject>
#include "StructureType.h"

class TriangulateScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TriangulateScene(QObject* parent = nullptr);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void selectStructure(const Point& point);
    void selectStructure(const Edge& edge);
    void selectStructure(const Triangle& triangle);

private:
    Triangulation m_triangulation;
    StructureType m_structureType{NodesWithNeighbours};
};

#endif // TRIANGULATESCENE_H
