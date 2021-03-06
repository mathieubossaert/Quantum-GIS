
#ifndef QGSVECTORGRADIENTCOLORRAMPV2DIALOG_H
#define QGSVECTORGRADIENTCOLORRAMPV2DIALOG_H

#include <QDialog>

#include "ui_qgsvectorgradientcolorrampv2dialogbase.h"

class QgsVectorGradientColorRampV2;

class GUI_EXPORT QgsVectorGradientColorRampV2Dialog : public QDialog, private Ui::QgsVectorGradientColorRampV2DialogBase
{
    Q_OBJECT

  public:
    QgsVectorGradientColorRampV2Dialog( QgsVectorGradientColorRampV2* ramp, QWidget* parent = NULL );

  public slots:
    void setColor1();
    void setColor2();

    void toggledStops( bool on );
    void addStop();
    void removeStop();

    void stopDoubleClicked( QTreeWidgetItem* item, int column );

  protected:

    void updatePreview();
    void setStopColor( QTreeWidgetItem* item, QColor color );

    QgsVectorGradientColorRampV2* mRamp;

    static const int StopColorRole = Qt::UserRole + 1;
    static const int StopOffsetRole = Qt::UserRole + 2;
};

#endif
