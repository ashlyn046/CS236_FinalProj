#ifndef PROJECT1_STARTER_CODE_DATABASE_H
#define PROJECT1_STARTER_CODE_DATABASE_H
#include <map>
#include "Structures/Relation.h"

class Database {
private:
    std::map<std::string, Relation> relationMap;

public:
    Database() = default;
    ~Database() = default;
    void addRelation(const std::string& name, const Relation& relation);
    void addTuple(const std::string& name, const Tuple& tuple);
    Relation getRelation(const std::string& name);
    Relation& getRelationByReference(std::string name);
    int getSize();
    void toString() const;

};


#endif //PROJECT1_STARTER_CODE_DATABASE_H
