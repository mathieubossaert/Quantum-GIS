#ifndef QGSSPATIALITEDATAITEMS_H
#define QGSSPATIALITEDATAITEMS_H

#include "qgsdataitem.h"

class QgsSLLayerItem : public QgsLayerItem
{
    Q_OBJECT
  public:
    QgsSLLayerItem( QgsDataItem* parent, QString name, QString path, QString uri, LayerType layerType );

    QList<QAction*> actions();

  public slots:
    void deleteLayer();
};

class QgsSLConnectionItem : public QgsDataCollectionItem
{
    Q_OBJECT
  public:
    QgsSLConnectionItem( QgsDataItem* parent, QString name, QString path );
    ~QgsSLConnectionItem();

    QVector<QgsDataItem*> createChildren();
    virtual bool equal( const QgsDataItem *other );

    virtual QList<QAction*> actions();

    virtual bool acceptDrop() { return true; }
    virtual bool handleDrop( const QMimeData * data, Qt::DropAction action );

  public slots:
    void editConnection();
    void deleteConnection();

  protected:
    QString mDbPath;
};

class QgsSLRootItem : public QgsDataCollectionItem
{
    Q_OBJECT
  public:
    QgsSLRootItem( QgsDataItem* parent, QString name, QString path );
    ~QgsSLRootItem();

    QVector<QgsDataItem*> createChildren();

    virtual QWidget * paramWidget();

    virtual QList<QAction*> actions();

  public slots:
    void connectionsChanged();
    void newConnection();
    void createDatabase();
};


#endif // QGSSPATIALITEDATAITEMS_H
