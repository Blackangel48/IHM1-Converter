#include "widget.h"
#include "typeDef.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    itsConverter = new converter;

    this->setWindowTitle("Feet Converter");

    valueTitle = new QLabel;
    valueLine = new QLineEdit;
    valueSlider = new QSlider;
    mtof = new QRadioButton;
    ftom = new QRadioButton;
    valueConverted = new QLabel;
    unitLabel = new QLabel;
    layout = new QGridLayout(this);

    valueTitle->setText("Value to convert");
    valueLine->setText("0");
    mtof->setText("Meters to Feet");
    ftom->setText("Feet to Meters");
    valueConverted->setText("0");
    unitLabel->setText("Feet");

    itsConverter->setUnitConvertInto(Feet);
    mtof->setChecked(1);
    valueSlider->setOrientation(Qt::Horizontal);

    layout->addWidget(valueTitle,0,0);
    layout->addWidget(valueLine,0,2);
    layout->addWidget(valueSlider,1,2);
    layout->addWidget(mtof,2,0);
    layout->addWidget(ftom,3,0);
    layout->addWidget(valueConverted,4,0);
    layout->addWidget(unitLabel,4,2);

    connect(valueSlider,SIGNAL(sliderPressed()),  this,SLOT(updateLineEdit()));
    connect(valueSlider,&QSlider::sliderMoved,  this,&Widget::updateLineEdit);

    connect(valueLine,SIGNAL(textEdited(QString)),  this,SLOT(updateSlider()));

    connect(mtof,SIGNAL(clicked()),  this,SLOT(updateConvertIntoFeet()));
    connect(ftom,SIGNAL(clicked()),  this,SLOT(updateConvertIntoMeters()));
}

Widget::~Widget()
{
    delete itsConverter;
}

void Widget::convert()
{
    valueConverted->setText(QString::number(itsConverter->convert()));
}

void Widget::updateLineEdit()
{
    valueLine->setText(QString::number(valueSlider->value()));
    itsConverter->setValue(valueSlider->value());
    convert();
}

void Widget::updateSlider()
{
    valueSlider->setSliderPosition(QString(valueLine->text()).toDouble());
    itsConverter->setValue(valueLine->text().toDouble());
    convert();
}

void Widget::updateConvertIntoFeet()
{
    unitLabel->setText("Feet");
    itsConverter->setUnitConvertInto(Feet);
    convert();
}

void Widget::updateConvertIntoMeters()
{
    unitLabel->setText("Meters");
    itsConverter->setUnitConvertInto(Meters);
    convert();
}
