#ifndef CUSTOMRECTITEM_H
#define CUSTOMRECTITEM_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QPainter>

class CustomRectItem : public QGraphicsRectItem
{
public:
    CustomRectItem(QGraphicsItem * parent = 0);
    void dropEvent(QGraphicsSceneDragDropEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setText(const QString& text);
    QString text() const {return m_text;}
private:
    QString m_text;
};

#endif // CUSTOMRECTITEM_H
