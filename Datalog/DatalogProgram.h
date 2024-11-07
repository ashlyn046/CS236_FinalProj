#ifndef PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
#define PROJECT1_STARTER_CODE_DATALOGPROGRAM_H

#include "Structures/Rule.h"
#include "Structures/Predicate.h"
#include <vector>
#include <string>
#include <set>

class DatalogProgram {
private:
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Predicate> queries;
    std::vector<Rule> rules;
    std::set<std::string> domain;

public:
    DatalogProgram() = default;
    ~DatalogProgram() = default;
    void addScheme(const Predicate& pred);
    void addFact(const Predicate& pred);
    void addRule(const Rule& rule);
    void addQuery(const Predicate& pred);
    void addDomain(const std::string& d);
    void schemeToString();
    void factToString();
    void ruleToString();
    void queryToString();
    void domainToString();
    void toString();
    const std::vector<Predicate> &getSchemes() const;
    const std::vector<Predicate> &getFacts() const;
    const std::vector<Predicate> &getQueries() const; //I might need to add the const back
    const std::vector<Rule> &getRules() const;
};

#endif //PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
