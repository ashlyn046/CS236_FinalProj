//
// Created by Alison Day on 9/19/22.
//

#ifndef PROJECT1_STARTER_CODE_RULESAUTOMATON_H
#define PROJECT1_STARTER_CODE_RULESAUTOMATON_H

#include "Automaton.h"

class RulesAutomaton : public Automaton{
private:
    void S1(const std::string &input);

public:
    RulesAutomaton() : Automaton(TokenType::RULES) {}  // Call the base constructor

    void S0(const std::string &input) override;
};

#endif //PROJECT1_STARTER_CODE_RULESAUTOMATON_H
