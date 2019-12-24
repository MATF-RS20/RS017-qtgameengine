#include "screeloader.h"
#include "mainwindow.h"

//#include "mainwindow.cpp"
SceneLoader::SceneLoader()
{

}
void SceneLoader::setFilePath(std::string path){
    filePath = path;
}
std::string SceneLoader::getFilePath(){
    return filePath;
}
QGraphicsScene* SceneLoader::getScene() const{
    return scene;
}
bool SceneLoader::sceneSave(GameBuilder* scene){
    std::cout << "Usao"<<std::endl;
    QJsonObject objectToJson;
   /*  QPixmap texture;
    bool focused;
    QList<QLineEdit*> rectangleInfo;
    QLineEdit* line;
    QPushButton* rectangleUpdate;*/
    QJsonArray parentJson;
    for(QGraphicsItem* item: scene->getParent()->items()){
        QJsonObject objectToJson;
        if(item->type() == 1){
           Rectangle* eObj = qgraphicsitem_cast<Rectangle*>(item);
           //qDebug()<< scene->getComponentInfo();
           objectToJson["name"] = "Rectangle";
           qlonglong id = eObj->getId();
           objectToJson["id"] = id;
           objectToJson["x"] = eObj->pos().toPoint().rx();
           objectToJson["y"] = eObj->pos().toPoint().ry();
           objectToJson["height"] =  eObj->getHeight();
           objectToJson["width"] = eObj->getWidth();
          // qDebug()<< eObj.get();

        }else if(item->type() == 2){

           Enemy* eObj = qgraphicsitem_cast<Enemy*>(item);
           objectToJson["name"] = "Enemy";
           objectToJson["x"] = eObj->pos().toPoint().rx();
           objectToJson["y"] = eObj->pos().toPoint().ry();
           objectToJson["height"] =  eObj->getHeight();
           objectToJson["width"] = eObj->getWidth();
           objectToJson["range"] = eObj->getRange();
           //objectToJson["look"] = eObj->getLook();
            qlonglong id = eObj->getId();
            objectToJson["id"] = id;
            objectToJson["focused"] = eObj->getFocused();

        }else if(item->type() == 3){

            Player* eObj = qgraphicsitem_cast<Player*>(item);
            objectToJson["name"] = "Player";
            objectToJson["x"] = eObj->pos().toPoint().rx();
            objectToJson["y"] = eObj->pos().toPoint().ry();
            objectToJson["height"] =  eObj->getHeight();
            objectToJson["width"] = eObj->getWidth();
        }

        parentJson.push_back(objectToJson);
    }
    QFile file_obj("file_path.json");
    if(!file_obj.open(QIODevice::WriteOnly)){
        qDebug()<<"Failed to open "<<"file_path.json";
        return false;
    }

    QJsonDocument json_doc(parentJson);
    QString json_string = json_doc.toJson();
    file_obj.write(json_string.toLocal8Bit());
    file_obj.close();
    return true;
}
QJsonArray SceneLoader::sceneLoad(QString fileName){
    QFile file_obj(fileName);
    if(!file_obj.open(QIODevice::ReadOnly)){
        qDebug()<<"Failed to open "<< fileName;
    }
    QTextStream file_text(&file_obj);
    QString json_string;
    json_string = file_text.readAll();
    file_obj.close();
    QByteArray json_bytes = json_string.toLocal8Bit();

    auto json_doc=QJsonDocument::fromJson(json_bytes);

    if(json_doc.isNull()){
        qDebug()<<"Failed to create JSON doc.";
        exit(2);
    }
    if(!json_doc.isArray()){
        qDebug() << "JSON doc is not an array.";
        exit(1);
    }

    QJsonArray json_array = json_doc.array();

    if(json_array.isEmpty()){
        qDebug() << "The array is empty";
        exit(1);
    }
    QJsonArray listObjects;
    for(int i=0; i< json_array.count(); ++i){
        QJsonObject obj = json_array.at(i).toObject();
        listObjects.push_back(obj);
    }
    return listObjects;
}
