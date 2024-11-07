#include "StringAutomata.h"

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if (!(input.substr(index, input.length()).empty())) {
        if (input[index] == '\n') {
            newLines++;
        }
        if (input[index] == '\'') {
            index++;
            inputRead++;
            if (input[index] == '\'')
            {
                index++;
                inputRead++;
                S1(input);
            }
            else{index--;} //index--?
        } else {
            inputRead++;
            index++;
            S1(input);
        }

    } else {
        type = TokenType::UNDEFINED; //only if a bad string
    }
}