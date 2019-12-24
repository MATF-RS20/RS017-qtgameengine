#ifndef SCENELOADER_H
#define SCENELOADER_H
#include <mainwindow.h>
#include <iostream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <string.h>
#include <QBuffer>
#include <QFileDialog>
#include <QDir>
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

    QString getBackgroundName() const;
    void setBackgroundName(const QString &value);

private:
    QGraphicsScene* scene;
    std::string filePath;
    QString BackgroundName;
};

#endif // SCENELOADER_H
