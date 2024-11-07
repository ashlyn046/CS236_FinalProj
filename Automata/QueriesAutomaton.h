#ifndef PROJECT1_STARTER_CODE_QUERIESAUTOMATON_H
#define PROJECT1_STARTER_CODE_QUERIESAUTOMATON_H

#include "Automata/Automaton.h"

class QueriesAutomaton : public Automaton{
private:
    void S1(const std::string &input);

public:
    QueriesAutomaton() : Automaton(TokenType::QUERIES) {}  // Call the base constructor

    void S0(const std::string &input) override;
};

#endif //PROJECT1_STARTER_CODE_QUERIESAUTOMATON_H
