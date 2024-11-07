#ifndef PROJECT1_STARTER_CODE_RULESAUTOMATON_H
#define PROJECT1_STARTER_CODE_RULESAUTOMATON_H

#include "Automata/Automaton.h"

class RulesAutomaton : public Automaton{
private:
    void S1(const std::string &input);

public:
    RulesAutomaton() : Automaton(TokenType::RULES) {}  // Call the base constructor

    void S0(const std::string &input) override;
};

#endif //PROJECT1_STARTER_CODE_RULESAUTOMATON_H
