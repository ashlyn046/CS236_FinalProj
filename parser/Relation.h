#ifndef PROJECT1_STARTER_CODE_RELATION_H
#define PROJECT1_STARTER_CODE_RELATION_H
#include "Tuple.h"
#include "Header.h"
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

class Relation{
private:
    std::string name;
    Header header;
    std::set<Tuple> tuples;
    std::vector<std::pair<int, int>> matchingHeaderIndices;
    std::vector<int> uniqueHeaderIndices;


public:
    Relation () = default;
    Relation(std::string nameVal, const Header& headerVal);
    ~Relation() = default;
    void setName(const std::string &relationName);
    const std::string &getName() const;
    const std::set<Tuple> &getTuples() const;
    void setHeader(const Header &relationHeader);
    const Header &getHeader() const;
    void addTuple(const Tuple& tuple);
    std::string relationToString();
    Relation* selectType1(int pos1, const std::string& val);
    Relation* selectType2(int pos1, int pos2);
    Relation* project(const std::vector<unsigned int>& pos);
    Relation* rename(const Header& header1);
    Relation join(const Relation& r1, const Relation& r2);
    Header combineHeaders(const Header& h1, const Header& h2);
    bool isJoinable(const Tuple& t1, const Tuple& t2);
    Tuple combineTuples(const Tuple& t1, const Tuple& t2);
    bool doUnion(const Relation& r);
};

#endif //PROJECT1_STARTER_CODE_RELATION_H
