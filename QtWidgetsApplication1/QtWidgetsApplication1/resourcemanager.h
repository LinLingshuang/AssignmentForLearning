#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QObject>
#include "resource.h"
#include "utils.h"

class ResourceManager : public QObject
{
    Q_OBJECT
public:
    explicit ResourceManager(QObject* parent = nullptr);

    void addResource(ResourceType type, QPoint grid);

    void initPicture();

    Resource* checkResource(QPoint checkPoint);

    Resource* getResources(int i);
    int getResourcesNum() { return (int)allResources.size(); }

private slots:
    void onResourceDepleted(Resource* r);

signals:
    void resourceAdded(Resource * r);

private:
    std::vector<Resource*> allResources;
    std::vector<Resource*> depletedResources; // 存储已耗尽的资源
};

#endif // RESOURCEMANAGER_H
