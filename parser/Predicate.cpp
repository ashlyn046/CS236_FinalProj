#include "Predicate.h"
#include <string>

void Predicate::setID(std::string id)
{
    ID = std::move(id);
}

std::string Predicate::getID() const
{
    return ID;
}

void Predicate::setParameterList(std::vector<Parameter*> paramList)
{
    parameterList = std::move(paramList);
}

std::vector<Parameter*> Predicate::getParameterList() const
{
    return parameterList;
}

std::string Predicate::toString()
{
    std::string stringVal = ID + "(";
    for (unsigned int i = 0; i < parameterList.size(); i++)
    {
        if (i == 0)
            stringVal += parameterList.at(i)->toString();
        else
            stringVal += "," + parameterList.at(i)->toString();
    }
    stringVal = stringVal + ")";
    return stringVal;
}