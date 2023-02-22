//
// Created by Alison Day on 10/1/22.
//

#include "Parser.h"
#include <iostream>
#include <utility>

Parser::Parser(std::vector<Token*> vectorOfTokens)
{
    tokenVector = std::move(vectorOfTokens);
}

Parser::~Parser()
{
    for (auto & i : tokenVector)
        delete i;

    std::cout << "parser deconstruct successful" << std::endl;
}

void Parser::parse()
{
        eraseComments();

        match(TokenType::SCHEMES);
        match(TokenType::COLON);
        scheme();
        schemeList();

        match(TokenType::FACTS);
        match(TokenType::COLON);
        factList();

        match(TokenType::RULES);
        match(TokenType::COLON);
        ruleList();

        match(TokenType::QUERIES);
        match(TokenType::COLON);
        query();
        queryList();
}

void Parser::match(TokenType type)
{
    if (tokenVector.at(index)->getTypeOfToken() == type)
        index++;
    else
        throw tokenVector.at(index); //Throws a pointer -- should not throw a pointer come back and fix?
}

void Parser::schemeList()
{
    if (tokenVector.at(index)->getTypeOfToken() == TokenType::ID)
    {
        scheme();
        schemeList();
    }
}

void Parser::factList()
{
    if (tokenVector.at(index)->getTypeOfToken() == TokenType::ID)
    {
        fact();
        factList();
    }
}

void Parser::ruleList()
{
    if (tokenVector.at(index)->getTypeOfToken() == TokenType::ID)
    {
        rule();
        ruleList();
    }
}

void Parser::queryList()
{
    if (tokenVector.at(index)->getTypeOfToken() == TokenType::ID)
    {
        query();
        queryList();
    }
}

void Parser::scheme()
{
    match(TokenType::ID);
    std::string id;
    id = tokenVector.at(index - 1)->getActualValue();
    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);

    std::vector<Parameter*> paramList;
    paramList.push_back(new Parameter(tokenVector.at(index - 1)->getActualValue()));
    idList(paramList);
    match(TokenType::RIGHT_PAREN);

    Predicate schemePredicate;
    schemePredicate.setID(id);
    schemePredicate.setParameterList(paramList);
    dlp.addScheme(schemePredicate);
}

void Parser::fact()
{
    match(TokenType::ID);
    std::string id;
    id = tokenVector.at(index - 1)->getActualValue();
    match(TokenType::LEFT_PAREN);
    match(TokenType::STRING);

    std::vector<Parameter*> paramList;
    paramList.push_back(new Parameter(tokenVector.at(index - 1)->getActualValue()));
    dlp.addDomain(tokenVector.at(index - 1)->getActualValue());
    stringList(paramList);
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);

    Predicate factPredicate;
    factPredicate.setID(id);
    factPredicate.setParameterList(paramList);
    dlp.addFact(factPredicate);
}

void Parser::rule()
{
    Predicate headPred;
    headPredicate(headPred);
    match(TokenType::COLON_DASH);

    Predicate body1;
    predicate(body1);
    std::vector<Predicate> bodyPredicates;
    bodyPredicates.push_back(body1);
    predicateList(bodyPredicates);
    match(TokenType::PERIOD);

    Rule rule;
    rule.setHeadPredicate(headPred);
    rule.setBodyPredicates(bodyPredicates);
    dlp.addRule(rule);
}

void Parser::query()
{
    Predicate pred;
    predicate(pred);
    match(TokenType::Q_MARK);

    dlp.addQuery(pred);
}

void Parser::headPredicate(Predicate &headPred)
{
    if (tokenVector.at(index)->getTypeOfToken() == TokenType::ID)
    {
        match(TokenType::ID);
        std::string id = tokenVector.at(index - 1)->getActualValue();
        match(TokenType::LEFT_PAREN);
        match(TokenType::ID);

        std::vector<Parameter*> paramList;
        paramList.push_back(new Parameter(tokenVector.at(index - 1)->getActualValue()));
        idList(paramList);
        match(TokenType::RIGHT_PAREN);

        headPred.setID(id);
        headPred.setParameterList(paramList);
    }
}

void Parser::predicate(Predicate &pred)
{
    if (tokenVector.at(index)->getTypeOfToken() == TokenType::ID)
    {
        match(TokenType::ID);
        std::string id;
        id = tokenVector.at(index - 1)->getActualValue();
        match(TokenType::LEFT_PAREN);

        std::vector<Parameter*> paramList;
        parameter();
        paramList.push_back(new Parameter(tokenVector.at(index - 1)->getActualValue()));
        parameterList(paramList);
        match(TokenType::RIGHT_PAREN);

        pred.setID(id);
        pred.setParameterList(paramList);
    }
}

void Parser::predicateList(std::vector<Predicate> &bodyPredicates)
{
    if (tokenVector.at(index)->getTypeOfToken() == TokenType::COMMA)
    {
        match(TokenType::COMMA);
        Predicate pred;
        predicate(pred);
        bodyPredicates.push_back(pred);
        predicateList(bodyPredicates);
    }
}

void Parser::parameterList(std::vector<Parameter*> &paramList)
{
    if (tokenVector.at(index)->getTypeOfToken() == TokenType::COMMA)
    {
        match(TokenType::COMMA);
        parameter();
        paramList.push_back(new Parameter(tokenVector.at(index - 1)->getActualValue()));
        parameterList(paramList);
    }
}

void Parser::stringList(std::vector<Parameter*> &paramList)
{
    if (tokenVector.at(index)->getTypeOfToken() == TokenType::COMMA)
    {
        match(TokenType::COMMA);
        match(TokenType::STRING);
        paramList.push_back(new Parameter(tokenVector.at(index - 1)->getActualValue()));

        dlp.addDomain(tokenVector.at(index - 1)->getActualValue());
        stringList(paramList);
    }
}

void Parser::idList(std::vector<Parameter*> &paramList)
{
    if (tokenVector.at(index)->getTypeOfToken() == TokenType::COMMA)
    {
        match(TokenType::COMMA);
        match(TokenType::ID);
        paramList.push_back(new Parameter(tokenVector.at(index - 1)->getActualValue()));
        idList(paramList);
    }
}

void Parser::parameter()
{
    if (tokenVector.at(index)->getTypeOfToken() == TokenType::STRING)
        match(TokenType::STRING);
    else
        match(TokenType::ID);
}

DatalogProgram Parser::getDlp()
{
    return dlp;
}

void Parser::eraseComments()
{
    int vectorSize = tokenVector.size(); //Come back and fix this warning if the pass off cases don't work
    for(int i = 0; i < vectorSize; i++)
    {
        if (tokenVector.at(i)->getTypeOfToken() != TokenType::COMMENT)
            tokenVector.push_back(tokenVector.at(i));
    }
    tokenVector.erase(tokenVector.begin(), tokenVector.begin()+vectorSize);
}


