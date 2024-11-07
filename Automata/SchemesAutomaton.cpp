#include "SchemesAutomaton.h"

void SchemesAutomaton::S0(const std::string& input) {
    if (input[index] == 'S') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomaton::S1(const std::string& input) {
    if (input[index] == 'c') {
        index++;
        inputRead++;
        if (input[index] == 'h')
        {
          index++;
          inputRead++;
            if (input[index] == 'e')
            {
                index++;
                inputRead++;
                if (input[index] == 'm')
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
                    }  else {
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
    }else {
        Serr();
    }
}
