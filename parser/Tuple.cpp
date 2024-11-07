#include "Tuple.h"
#include <utility>

Tuple::Tuple(std::vector<std::string> vectorOfStrings)
{
    values = std::move(vectorOfStrings);
}

bool Tuple::operator<(const Tuple &rhs) const
{
    return values < rhs.values;
}

const std::vector<std::string>& Tuple::getValues() const
{
    return values;
}

void Tuple::addValue(const std::string& stringVal)
{
    values.push_back(stringVal);
}


