//
// Created by Alison Day on 9/19/22.
//

#include "MultiplyAutomata.h"

void MultiplyAutomaton::S0(const std::string& input) {
    if (input[index] == '*') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}