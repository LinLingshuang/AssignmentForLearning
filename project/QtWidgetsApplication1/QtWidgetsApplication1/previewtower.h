#ifndef PREVIEWTOWER_H
#define PREVIEWTOWER_H

#include "tower.h"
#include "QPixmap"
#include "utils.h"

class PreviewTower : public QGraphicsItem
{
public:
	PreviewTower(TowerType type);           // 构造函数，指定塔类型

	void setGridPos(const QPoint grid);     // 设置网格位置
	void setValid(bool ok) { isValid = ok; }// 设置是否可以放置

    TowerType getTowerType() { return type; }
    QPoint getGridPos() const { return gridPos; }

	QRectF boundingRect() const override;   // 返回边界矩形
    void paint(QPainter* painter,
               const QStyleOptionGraphicsItem* option,
               QWidget* widget) override;

private:
    TowerType type;
    bool isValid = false;
    int attackRadius;
    QPixmap picture;
    QPoint gridPos;
};

#endif // PREVIEWTOWER_H
