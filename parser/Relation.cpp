#include "Relation.h"
#include <utility>

Relation::Relation(std::string nameVal, const Header& headerVal)
{
    this->name = std::move(nameVal);
    this-> header = headerVal;
}

void Relation::setName(const std::string &relationName)
{
    Relation::name = relationName;
}

const std::string &Relation::getName() const
{
    return name;
}

const std::set<Tuple> &Relation::getTuples() const
{
    return tuples;
}

void Relation::setHeader(const Header &relationHeader)
{
    Relation::header = relationHeader;
}

const Header& Relation::getHeader() const
{
    return header;
}

void Relation::addTuple(const Tuple& tuple)
{
    tuples.insert(tuple);
}

std::string Relation::relationToString()
{
    std::ostringstream stringVal;
    if (header.getAttributes().empty())
        return stringVal.str();
    for (const auto& tupleIterator : tuples)
    {
        stringVal << "  ";
        for (unsigned int i = 0; i < header.getAttributes().size(); i++)
        {
            if (i == (header.getAttributes().size() - 1))
                stringVal << header.getAttributes().at(i) << "=" << tupleIterator.getValues().at(i) << std::endl;
            else
                stringVal << header.getAttributes().at(i) << "=" << tupleIterator.getValues().at(i) << ", ";
        }
    }
    return stringVal.str();
}

Relation* Relation::selectType1(int pos1, const std::string& val)
{
    auto *tempRelation = new Relation(name, header);
    for (const auto& tupleIterator : tuples)
    {
        if (tupleIterator.getValues().at(pos1) == val)
            tempRelation->addTuple(tupleIterator);
    }
    return tempRelation;
}

Relation* Relation::selectType2(int pos1, int pos2)
{
    auto *tempRelation = new Relation(name, header);
    for (const auto& tupleIterator : tuples)
    {
        if (tupleIterator.getValues().at(pos1) == tupleIterator.getValues().at(pos2))
            tempRelation->addTuple(tupleIterator);
    }
    return tempRelation;
}

Relation* Relation::project(const std::vector<unsigned int>& pos)
{
    auto *tempRelation = new Relation(name, header);
    for (const auto& tupleIterator : tuples)
    {
        Tuple tempTuple;
        for (unsigned int po : pos)
            tempTuple.addValue(tupleIterator.getValues().at(po));

        tempRelation->addTuple(tempTuple);
    }
    return tempRelation;
}

Relation* Relation::rename(const Header& header1)
{
    auto *tempRelation = new Relation(name, header1);
    for (const auto& tupleIterator : tuples)
    {
        Tuple tempTuple;
        for (const auto & i : tupleIterator.getValues())
            tempTuple.addValue(i);

        tempRelation->addTuple(tempTuple);
    }
    return tempRelation;
}

Relation Relation::join(const Relation& r1, const Relation& r2)
{
    Header newHeader = combineHeaders(r1.getHeader(), r2.getHeader());
    Relation newRel(r1.getName(), newHeader);

    for (const auto& tupleIterator1 : r1.getTuples())
    {
        for (const auto &tupleIterator2: r2.getTuples())
        {
            if (isJoinable(tupleIterator1, tupleIterator2))
            {
                Tuple newTuple = combineTuples(tupleIterator1, tupleIterator2);
                newRel.addTuple(newTuple);
            }
        }
    }
    return newRel;
}

Header Relation::combineHeaders(const Header& h1, const Header& h2)
{
    Header newHeader = h1;
    int counter1 = 0;
    matchingHeaderIndices.clear();
    uniqueHeaderIndices.clear();

    for (const auto& attributeIterator2 : h2.getAttributes())
    {
        bool seen = false;
        int counter2 = 0;
        for (const auto& attributeIterator1 : h1.getAttributes())
        {
            if (attributeIterator2 == attributeIterator1)
            {
                seen = true;
                matchingHeaderIndices.emplace_back(counter2, counter1);
            }
            counter2++;
        }
        if (!seen)
        {
            newHeader.addAttributes(attributeIterator2);
            uniqueHeaderIndices.push_back(counter1);
        }
        counter1++;
    }
    return newHeader;
}

bool Relation::isJoinable(const Tuple& t1, const Tuple& t2)
{
    bool isJoinable = true;

    for (auto & matchingHeaderIndice : matchingHeaderIndices)
    {
        if (t1.getValues().at(matchingHeaderIndice.first) != t2.getValues().at(matchingHeaderIndice.second))
            isJoinable = false;
    }
    return isJoinable;
}

Tuple Relation::combineTuples(const Tuple& t1, const Tuple& t2)
{
    Tuple newTuple = t1;

    for (int uniqueHeaderIndice : uniqueHeaderIndices)
        newTuple.addValue(t2.getValues().at(uniqueHeaderIndice));

    return newTuple;
}

bool Relation::doUnion(const Relation& relation)
{
    bool addedTuples = false;

    for (const auto& argTuplesIterator : relation.getTuples())
    {
        if (tuples.insert(argTuplesIterator).second)
        {
            addedTuples = true;
            std::cout << "  ";
            for (unsigned int i = 0; i < argTuplesIterator.getValues().size(); i++) {
                if (i == (argTuplesIterator.getValues().size() - 1)) {
                    std::cout << header.getAttributes().at(i) << "=" << argTuplesIterator.getValues().at(i) << std::endl;
                } else {
                    std::cout << header.getAttributes().at(i) << "=" << argTuplesIterator.getValues().at(i) << ", ";
                }
            }
        }
    }
    return addedTuples;
}