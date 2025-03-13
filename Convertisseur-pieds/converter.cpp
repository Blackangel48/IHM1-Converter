#include "converter.h"
#include "typeDef.h"

converter::converter() {}

double converter::convert()
{
    switch (unitConvertInto) {
    case Meters:
        return value/Ratio;
        break;
    case Feet:
        return value*Ratio;
        break;
    default:
        break;
    }
}

void converter::setValue(double val)
{
    value = val;
}

double converter::getValue()
{
    return value;
}

void converter::setUnitConvertInto(Unit unit)
{
    unitConvertInto = unit;
}
