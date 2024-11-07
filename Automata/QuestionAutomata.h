#ifndef PROJECT1_STARTER_CODE_QUESTIONAUTOMATA_H
#define PROJECT1_STARTER_CODE_QUESTIONAUTOMATA_H

#include "Automaton.h"

class QuestionAutomaton : public Automaton
{
public:
    QuestionAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //PROJECT1_STARTER_CODE_QUESTIONAUTOMATA_H
