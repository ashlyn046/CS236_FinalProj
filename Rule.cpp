#include "Rule.h"
#include "Predicate.h"
#include <utility>
#include <vector>
#include <iostream>

void Rule::setHeadPredicate(const Predicate& headPred)
{
    headPredicate = headPred;
}

void Rule::setBodyPredicates(std::vector<Predicate> bodyPredicate)
{
    bodyPredicates = std::move(bodyPredicate);
}

Predicate Rule::getHeadPredicate()
{
    return headPredicate;
}

std::vector<Predicate> Rule::getBodyPredicates()
{
    return bodyPredicates;
}

std::string Rule::toString()
{
    std::string theRule;
    theRule = headPredicate.toString() + " :- ";
    for (unsigned int i = 0; i < bodyPredicates.size(); i++)
    {
        if (i == 0)
            theRule += bodyPredicates.at(i).toString();
        else
            theRule += "," + bodyPredicates.at(i).toString();
    }

    theRule += ".";

    return theRule;
}
