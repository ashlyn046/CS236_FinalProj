#include "Automata/RulesAutomaton.h"

void RulesAutomaton::S0(const std::string& input) {
    if (input[index] == 'R') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void RulesAutomaton::S1(const std::string& input) {
    if (input[index] == 'u') {
        index++;
        inputRead++;
        if (input[index] == 'l')
        {
            index++;
            inputRead++;
            if (input[index] == 'e')
            {
                index++;
                inputRead++;
                if (input[index] == 's')
                {
                    inputRead++;
                }else {
                    Serr();
                }
            }else {
                Serr();
            }
        }else {
            Serr();
        }
    }else {
        Serr();
    }
}
