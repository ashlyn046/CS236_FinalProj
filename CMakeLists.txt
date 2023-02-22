cmake_minimum_required(VERSION 3.23)
project(Project1_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1_Starter_Code
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h PeriodAutomaton.cpp PeriodAutomaton.h CommaAutomaton.cpp CommaAutomaton.h QuestionAutomata.cpp QuestionAutomata.h RightParenthesesAutomaton.cpp RightParenthesesAutomaton.h LeftParenthesesAutomaton.cpp LeftParenthesesAutomaton.h MultiplyAutomata.cpp MultiplyAutomata.h AdditionAutomata.cpp AdditionAutomata.h SchemesAutomaton.cpp SchemesAutomaton.h FactsAutomaton.cpp FactsAutomaton.h RulesAutomaton.cpp RulesAutomaton.h QueriesAutomaton.cpp QueriesAutomaton.h IdentifierAutomaton.cpp IdentifierAutomaton.h StringAutomata.cpp StringAutomata.h CommentAutomaton.cpp CommentAutomaton.h Parser.cpp Parser.h DatalogProgram.cpp DatalogProgram.h Parameter.cpp Parameter.h Predicate.cpp Predicate.h Rule.cpp Rule.h Database.cpp Database.h Tuple.cpp Tuple.h Header.cpp Header.h Relation.cpp Relation.h Interpreter.cpp Interpreter.h)
