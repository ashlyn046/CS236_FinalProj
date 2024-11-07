#include "interpreter/Interpreter.h"

Interpreter::Interpreter(const DatalogProgram& datalogProgramVal)
{
    datalogProgram = datalogProgramVal;
}

Database Interpreter::getDb() const
{
    return database;
}

void Interpreter::run()
{
    runSchemes();
    runFacts();
    runRules();
    runQueries();
}

void Interpreter::runSchemes()
{
    for (const auto & i : datalogProgram.getSchemes())
    {
        std::string name;
        name = i.getID();
        Header headerAttributes;
        std::vector<std::string> attributes;

        for (unsigned int j = 0; j < i.getParameterList().size(); j++)
            attributes.push_back(i.getParameterList().at(j)->getParameter());

        headerAttributes.setAttributes(attributes);
        Relation relation(name, headerAttributes);
        database.addRelation(name, relation);
    }
}

void Interpreter::runFacts()
{
    for (const auto & i : datalogProgram.getFacts())
    {
        std::string name;
        name = i.getID();
        std::vector<std::string> values;

        for (unsigned int j = 0; j < i.getParameterList().size(); j++)
            values.push_back(i.getParameterList().at(j)->getParameter());

        Tuple tuple(values);
        database.addTuple(name, tuple);
    }
}

void Interpreter::runRules()
{
    int sizeBefore;
    int sizeAfter;
    int numPasses{0};
    std::vector<Rule> ruleVector{datalogProgram.getRules()};
    std::cout << "Rule Evaluation" << std::endl;
    do{
        sizeBefore = database.getSize();
        for(auto & i : ruleVector)
        {
            std::cout << i.toString() << std::endl;
            evaluateRule(i);
        }
        sizeAfter = database.getSize();
        numPasses++;
    } while(sizeBefore != sizeAfter);
    std::cout << std::endl;
    std::cout << "Schemes populated after " << numPasses << " passes through the Rules." << std::endl;
    std::cout << std::endl;

}

void Interpreter::runQueries()
{
    std::cout << "Query Evaluation" << std::endl;
    for (auto & query : datalogProgram.getQueries())
    {
        Relation* answer = evaluateQuery(query);
        std::cout << query.getID() << "(";
        for (unsigned int i = 0; i < query.getParameterList().size(); i++)
        {
            if (i == (query.getParameterList().size()) - 1)
                std::cout << query.getParameterList().at(i)->getParameter();
            else
                std::cout << query.getParameterList().at(i)->getParameter() << ",";
        }
        std::cout << ")? ";
        if (answer->getTuples().empty())
            std::cout << "No" << std::endl;
        else
            std::cout << "Yes(" << answer->getTuples().size() << ")" << std::endl;

        std::cout << answer->relationToString();
    }
}

Relation* Interpreter::evaluateQuery(const Predicate& predicate)
{
    auto *answer = new Relation;
    *answer = database.getRelation(predicate.getID());

    std::vector<unsigned int> positions;
    std::vector<std::string> values;
    std::map<std::string, unsigned int> posValueMap;
    unsigned int index = 0;

    for (auto currParam : predicate.getParameterList())
    {
        if (currParam->isConstant())
            answer = answer->selectType1(index, currParam->getParameter());
        else
        {
            if (posValueMap.find(currParam->getParameter()) == posValueMap.end())
            {
                positions.push_back(index);
                values.push_back(currParam->getParameter());
                posValueMap.insert({currParam->getParameter(), index});
            }
            else
                answer = answer->selectType2(index, posValueMap.at(currParam->getParameter()));
        }
        index++;
    }

    answer = answer->project(positions);
    Header tempHeader;
    tempHeader.setAttributes(values);
    answer = answer->rename(tempHeader);

    return answer;
}

bool Interpreter ::evaluateRule(Rule rule)
{
    bool added = false;
    std::vector<Relation> relationVector;
    std::vector<unsigned int> positions;

    for (unsigned int i = 0; i < rule.getBodyPredicates().size(); i++) {
        relationVector.push_back(*evaluateQuery(rule.getBodyPredicates().at(i)));
    }

    Relation joinedRel = relationVector.at(0);
    for (unsigned int i = 1; i < (relationVector.size()); i++)
        joinedRel = joinedRel.join(joinedRel, relationVector.at(i));

    for (unsigned int i = 0; i < rule.getHeadPredicate().getParameterList().size(); i++)
    {
        for (unsigned int j = 0; j < joinedRel.getHeader().getAttributes().size(); j++)
        {
            if (joinedRel.getHeader().getAttributes().at(j).compare(rule.getHeadPredicate().getParameterList().at(i)->getParameter()) == 0)
            {
                positions.push_back(j);
                break;
            }
        }
    }

    Relation finalRel = *joinedRel.project(positions);

    if (database.getRelationByReference(rule.getHeadPredicate().getID()).doUnion(finalRel))
        added = true;

    return added;
}