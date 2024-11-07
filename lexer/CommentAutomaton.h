//
// Created by Alison Day on 9/19/22.
//

#ifndef PROJECT1_STARTER_CODE_COMMENTAUTOMATON_H
#define PROJECT1_STARTER_CODE_COMMENTAUTOMATON_H

#include "Automaton.h"


class CommentAutomaton : public Automaton {
private:
    void S1(const std::string& input);

    void S2(const std::string& input);

    void S3(const std::string& input);

    void S4(const std::string& input);

public:
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}

    void S0(const std::string& input) override;

};

#endif
