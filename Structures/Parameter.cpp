#include "Structures/Parameter.h"

Parameter::Parameter(std::string stringVal)
{
    parameterVal = std::move(stringVal);
}

const std::string& Parameter::getParameter() const
{
    return parameterVal;
}

bool Parameter::isConstant()
{
    if (parameterVal.at(0) == '\'')
        return true;
    else
        return false;
}

std::string Parameter::toString()
{
    return parameterVal;
}
