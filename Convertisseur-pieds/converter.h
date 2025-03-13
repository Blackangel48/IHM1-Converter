#ifndef CONVERTER_H
#define CONVERTER_H

#include "typeDef.h"

class converter
{
private:
    double value=0;
    Unit unitConvertInto;
public:
    converter();
    double convert();
    void setValue(double val);
    double getValue();
    void setUnitConvertInto(Unit unit);
};

#endif // CONVERTER_H
