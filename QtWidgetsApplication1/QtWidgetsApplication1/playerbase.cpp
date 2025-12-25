#include "playerbase.h"
#include <QPixmap>
#include "utils.h"
#include <QPainter>
#include <QDebug>

PlayerBase::PlayerBase(QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent),
      health(INITCAMPHEALTH),
      maxHealth(INITCAMPHEALTH),
      size(TILESIZE * 2, TILESIZE * 2)
{
    // 加载不同状态的图片
    pixFull.load(":/picture/playerBase/base_frame1.png");
    pixLight.load(":/picture/playerBase/base_frame2.png");
    pixHeavy.load(":/picture/playerBase/base_frame3.png");
    pixCritical.load(":/picture/playerBase/base_frame3.png");
    
    // 初始化为满生命值图片
    updatePixmap();
    
    // 设置帐篷的位置（可以根据游戏需求调整）
    setPos(48*32, 7*32);
    
    // 设置帐篷的尺寸
    setScale(1.0);
    
    // 设置Z轴值，确保帐篷在正确的层级显示
    setZValue(MONSTERZVALUE - 1);
    
    qDebug() << "帐篷创建成功，初始生命值：" << health;
}

PlayerBase::~PlayerBase()
{
}

void PlayerBase::takeDamage(int damage)
{
    health -= damage;
    // 确保生命值不会小于0
    if (health < 0) {
        health = 0;
    }
    qDebug() << "帐篷受到伤害：" << damage << "，剩余生命值：" << health;
    
    // 更新帐篷图片状态
    updatePixmap();
    update();
    
    emit healthChanged(health);
    
    if (health <= 0) {
        emit tentDestroyed();
    }
}

// --------------------------------------------------------
QRectF PlayerBase::boundingRect() const
{
    return QRectF(-size.width() / 2, -size.height() / 2, size.width(), size.height());
}

// --------------------------------------------------------
void PlayerBase::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->drawPixmap(boundingRect().toRect(), currentPixmap);
}

// --------------------------------------------------------
void PlayerBase::updatePixmap()
{
    float ratio = static_cast<float>(health) / maxHealth;
    
    if (ratio >= 0.75f) {
        currentPixmap = pixFull;
    } else if (ratio >= 0.5f) {
        currentPixmap = pixLight;
    } else if (ratio >= 0.25f) {
        currentPixmap = pixHeavy;
    } else {
        currentPixmap = pixCritical;
    }
    
    // 设置当前图片
    setPixmap(currentPixmap);
}