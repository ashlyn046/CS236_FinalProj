//
// Created by Alison Day on 9/19/22.
//

#include "QuestionAutomata.h"


void QuestionAutomaton::S0(const std::string& input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}