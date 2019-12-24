#ifndef SCENELOADER_H
#define SCENELOADER_H
#include <mainwindow.h>
#include <iostream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <string.h>
#include <QBuffer>
class SceneLoader
{
public:
    SceneLoader();
    ~SceneLoader();
    SceneLoader(const SceneLoader& f);
    void setFilePath(std::string path);
    std::string getFilePath();
    QGraphicsScene* getScene() const;
    bool sceneSave(GameBuilder* scene);
    QJsonArray sceneLoad(QString fileName);

private:
    QGraphicsScene* scene;
    std::string filePath;
};

#endif // SCENELOADER_H
