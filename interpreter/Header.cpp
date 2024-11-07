//
// Created by Alison Day on 11/2/22.
//

#include "Header.h"
#include <utility>

void Header::setAttributes(std::vector<std::string> attributeVal)
{
    attributes = std::move(attributeVal);
}

const std::vector<std::string> &Header::getAttributes() const
{
    return attributes;
}

void Header::addAttributes(const std::string& stringVal)
{
    attributes.push_back(stringVal);
}
