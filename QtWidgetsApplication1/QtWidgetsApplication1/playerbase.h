#ifndef TENT_H
#define TENT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include "utils.h"

class PlayerBase : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit PlayerBase(QGraphicsItem* parent = nullptr);
    ~PlayerBase();

    void takeDamage(int damage);
    int getHealth() const { return health; }
    bool isDead() const { return health <= 0; }
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

signals:
    void tentDestroyed();
    void healthChanged(int newHealth);

private:
    void updatePixmap();

    int health;
    int maxHealth;
    QPixmap tentImage;
    QPixmap pixFull;
    QPixmap pixLight;
    QPixmap pixHeavy;
    QPixmap pixCritical;
    QPixmap currentPixmap;
    QSize size;
};

#endif // TENT_H