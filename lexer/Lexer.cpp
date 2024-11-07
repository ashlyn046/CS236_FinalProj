#include "lexer/Lexer.h"
#include "Automata/ColonAutomaton.h"
#include "Automata/ColonDashAutomaton.h"
#include "Automata/CommaAutomaton.h"
#include "Automata/PeriodAutomaton.h"
#include "Automata/QuestionAutomata.h"
#include "Automata/LeftParenthesesAutomaton.h"
#include "Automata/RightParenthesesAutomaton.h"
#include "Automata/MultiplyAutomata.h"
#include "Automata/AdditionAutomata.h"
#include "Automata/SchemesAutomaton.h"
#include "Automata/FactsAutomaton.h"
#include "Automata/RulesAutomaton.h"
#include "Automata/QueriesAutomaton.h"
#include "Automata/IdentifierAutomaton.h"
#include "Automata/StringAutomata.h"
#include "Automata/CommentAutomaton.h"
#include <cctype>
//#include <iostream>

Lexer::Lexer()
{
    CreateAutomata();
}

Lexer::~Lexer()
{
    for (auto & i : automata)
    {
        delete i;
    }
    for (auto & token : tokens)
    {
        delete token;
    }
}

void Lexer::CreateAutomata()
{
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QuestionAutomaton());
    automata.push_back(new LeftParenthesesAutomaton());
    automata.push_back(new RightParenthesesAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AdditionAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IdentifierAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
}

void Lexer::Run(std::string& input)
{
    int lineNumber{1};
    std::string inputValue{input};
    while(!inputValue.empty())
    {
        int maxRead = 0;
        Automaton* maxAutomaton = automata.at(0);

        while ((!inputValue.empty()) && isspace(inputValue.at(0)))
        {
            if (inputValue.at(0) == '\n')
            {
                lineNumber++;
            }
            inputValue.erase(0, 1);
        }

        if(inputValue.empty()) { break; }

        for (Automaton* automaton : automata)
        {
            int inputRead = automaton->Start(inputValue);
            if(inputRead > maxRead)
            {
                maxRead = inputRead;
                maxAutomaton = automaton;
            }
        }

        if(maxRead > 0)
        {
            std::string tokenAsString = inputValue.substr(0, maxRead);
            Token* newToken = maxAutomaton->CreateToken(tokenAsString, lineNumber);
            lineNumber = lineNumber + maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        else
        {
            maxRead = 1;
            std::string tokenString = inputValue.substr(0, maxRead);
            auto* newToken = new Token(TokenType::UNDEFINED, tokenString, lineNumber);
            tokens.push_back(newToken);
        }
        inputValue.erase(0, maxRead);

    }
    auto* endOfFile = new Token(TokenType::END_OF_FILE, "", lineNumber);
    tokens.push_back(endOfFile);
    std::string output = lexerToString();
    //std::cout << output; //I don't want the lexer output during Project 2!
}

std::string Lexer::lexerToString()
{
    std::string returnString;
    returnString = "";
    for (auto & token : tokens)
    {
        returnString += token->toString() + "\n";
    }
    returnString += "Total Tokens = " + std::to_string(tokens.size());

    return returnString;
}

std::vector<Token*> Lexer::getTokens()
{
    return tokens;
}