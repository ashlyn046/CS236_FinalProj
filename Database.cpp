//
// Created by Alison Day on 11/2/22.
//
#include "Database.h"

void Database::addRelation(const std::string& name, const Relation& relation)
{
    relationMap.insert({name, relation});
}

void Database::addTuple(const std::string& name, const Tuple& tuple)
{
    relationMap.at(name).addTuple(tuple);
}

Relation Database::getRelation(const std::string& name)
{
    return relationMap.find(name)->second;
}

Relation& Database::getRelationByReference(std::string name)
{
    return relationMap.at(name);
}

int Database :: getSize(){
    int size = 0;
    for(auto i = relationMap.begin(); i != relationMap.end(); ++i)
        for(Tuple x : i->second.getTuples())
            size++;
    return size;
}

void Database::toString() const
{
    std::string output;
    for (auto i: relationMap)
        std::cout << i.first << ": \n" << i.second.relationToString() << std::endl;
}


