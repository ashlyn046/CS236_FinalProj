//
// Created by Alison Day on 11/2/22.
//

#ifndef PROJECT1_STARTER_CODE_INTERPRETER_H
#define PROJECT1_STARTER_CODE_INTERPRETER_H

#include "Header.h"
#include "Tuple.h"
#include "Relation.h"
#include "Database.h"
#include "DatalogProgram.h"
#include "Predicate.h"
#include <map>
#include <set>

class Interpreter {
private:
    Database database;
    DatalogProgram datalogProgram;

public:
    explicit Interpreter(const DatalogProgram& datalogProgramVal);
    ~Interpreter() = default;
    Database getDb() const;
    void run();
    void runSchemes();
    void runFacts();
    void runRules();
    void runQueries();
    Relation* evaluateQuery(const Predicate& predicate);
    bool evaluateRule(Rule rule);
};

#endif //PROJECT1_STARTER_CODE_INTERPRETER_H
