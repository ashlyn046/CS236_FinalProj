#ifndef PROJECT1_STARTER_CODE_INTERPRETER_H
#define PROJECT1_STARTER_CODE_INTERPRETER_H

#include "Datalog_Structures/Header.h"
#include "Datalog_Structures/Tuple.h"
#include "Datalog_Structures/Relation.h"
#include "Datalog_Structures/Database.h"
#include "Datalog_Structures/DatalogProgram.h"
#include "Datalog_Structures/Predicate.h"
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
