#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QRadioButton>
#include <QGridLayout>

#include "typeDef.h"
#include "converter.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void convert();
    void updateLineEdit();
    void updateSlider();
    void updateConvertIntoFeet();
    void updateConvertIntoMeters();
private:
    converter * itsConverter;
    QGridLayout * layout;
    QLabel * valueTitle;
    QLineEdit * valueLine;
    QSlider * valueSlider;
    QRadioButton * mtof;//Meter To Feet
    QRadioButton * ftom;//Feet To Meter
    QLabel * valueConverted;
    QLabel * unitLabel;
};
#endif // WIDGET_H
