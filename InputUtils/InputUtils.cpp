#include "InputUtils.h"

int getIntValue(std::istream& in)
{
    int value;
    if (in >> value) return value;
    FATAL("Error while entering Int value");
}

double getDoubleValue(std::istream& in)
{
    double value;
    if (in >> value) return value;
    FATAL("Error while entering Double value");
}
