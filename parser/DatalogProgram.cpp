//
// Created by Alison Day on 10/1/22.
//

#include "DatalogProgram.h"
#include <iostream>

void DatalogProgram::addScheme(const Predicate& pred)
{
    schemes.push_back(pred);
}

void DatalogProgram::addFact(const Predicate& pred)
{
    facts.push_back(pred);
}

void DatalogProgram::addRule(const Rule& rule)
{
    rules.push_back(rule);
}

void DatalogProgram::addQuery(const Predicate& pred)
{
    queries.push_back(pred);
}

void DatalogProgram::addDomain(const std::string& dom)
{
    domain.insert(dom);
}

void DatalogProgram::schemeToString()
{
    std::cout << "Schemes(" << schemes.size() << "):" << std::endl;
    for (auto & scheme : schemes)
    {
        std::cout << "  " << scheme.getID() << "(";
        for (std::size_t j = 0; j < scheme.getParameterList().size(); j++)
        {
            if (j < (scheme.getParameterList().size() - 1))
                std::cout << scheme.getParameterList().at(j)->getParameter() << ",";
            else
                std::cout << scheme.getParameterList().at(j)->getParameter();
        }
        std::cout << ")" << std::endl;
    }
}

void DatalogProgram::factToString()
{
    std::cout << "Facts(" << facts.size() << "):" << std::endl;
    for (auto & fact : facts)
    {
        std::cout << "  " << fact.getID() << "(";
        for (std::size_t j = 0; j < fact.getParameterList().size(); j++)
        {
            if (j < (fact.getParameterList().size() - 1))
                std::cout << fact.getParameterList().at(j)->getParameter() << ",";
            else
                std::cout << fact.getParameterList().at(j)->getParameter();
        }
        std::cout << ")." << std::endl;
    }
}

void DatalogProgram::ruleToString()
{
    std::cout << "Rules(" << rules.size() << "):" << std::endl;
    for (auto & rule : rules)
    {
        std::cout << "  " << rule.getHeadPredicate().getID() << "(";
        for (std::size_t j = 0; j < rule.getHeadPredicate().getParameterList().size(); j++) //print head predicate
        {
            if (j < (rule.getHeadPredicate().getParameterList().size() - 1))
                std::cout << rule.getHeadPredicate().getParameterList().at(j)->getParameter() << ",";
            else
                std::cout << rule.getHeadPredicate().getParameterList().at(j)->getParameter();
        }
        std::cout << ") :- ";
        for (std::size_t j = 0; j < rule.getBodyPredicates().size(); j++) //print body predicates
        {
            std::cout << rule.getBodyPredicates().at(j).getID() << "(";
            for (std::size_t k = 0; k < rule.getBodyPredicates().at(j).getParameterList().size(); k++)
            {
                if (k < (rule.getBodyPredicates().at(j).getParameterList().size() - 1))
                    std::cout << rule.getBodyPredicates().at(j).getParameterList().at(k)->getParameter() << ",";
                else
                {
                    std::cout << rule.getBodyPredicates().at(j).getParameterList().at(k)->getParameter();
                    if(j != rule.getBodyPredicates().size()-1) //Accounts for the issue with no end parenthesis,
                        std::cout << "),";
                }
            }
        }
        std::cout << ")." << std::endl;
    }
}

void DatalogProgram::queryToString()
{
    std::cout << "Queries(" << queries.size() << "):" << std::endl;
    for (auto & query : queries)
    {
        std::cout << "  " << query.getID() << "(";
        for (std::size_t j = 0; j < query.getParameterList().size(); j++)
        {
            if (j < (query.getParameterList().size() - 1))
                std::cout << query.getParameterList().at(j)->getParameter() << ",";
            else
                std::cout << query.getParameterList().at(j)->getParameter();

        }
        std::cout << ")?" << std::endl;
    }
}

void DatalogProgram::domainToString()
{
    std::cout << "Domain(" << domain.size() << "):" << std::endl;
    for (const std::string& domainItem : domain)
    {
        std::cout << "  " << domainItem << std::endl;
    }
}

void DatalogProgram::toString()
{
    schemeToString();
    factToString();
    ruleToString();
    queryToString();
    domainToString();
}

const std::vector<Predicate> &DatalogProgram::getSchemes() const
{
    return schemes;
}
const std::vector<Predicate> &DatalogProgram::getFacts() const
{
    return facts;
}
const std::vector<Predicate> &DatalogProgram::getQueries() const
{
    return queries;
}
const std::vector<Rule> &DatalogProgram::getRules() const
{
    return rules;
}


