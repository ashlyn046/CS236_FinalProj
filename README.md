# CS236 Final Project - Datalog Interpreter

This project is the final project for BYU's CS236 course, taught by Brett Decker, Spring 2021. It combines elements from the 5 main projects for the course to develop a complete interpreter for Datalog programs. It includes a Lexer, Parser, and Execution Engine.

## Project Overview

This interpreter, built in C++, uses concepts from discrete structures, finite-state machines, and object-oriented design. The interpreter has three main components:

- **Lexer**: Scans the input program file and generates a list of tokens.
- **Parser**: Interprets tokens to validate the program structure.
- **Execution Engine (interpreter)**: Executes commands based on the parsed Datalog program.

### Why Tokens?

Tokens make the program easier for the computer to process by converting user-defined elements into a structured format. Each token holds:
1. A token type (e.g., `STRING`).
2. The specific input segment (e.g., `"Hello World"`).
3. Line number information.

### Project Breakdown

This project builds on previous projects:
- **Project 1**: Build the Lexer.
- **Project 2**: Construct the Parser.
- **Projects 3-5**: Develop the Execution Engine.

## Components

### Lexer
The **Lexer** uses a finite-state machine approach to tokenize input, breaking it down into predefined structures while tracking line numbers. The Lexer implements the `Parallel and Max` algorithm, where each automaton checks input and reads the longest valid segment, generating a token based on that match.

### Parser
The **Parser** receives tokens from the Lexer, arranging them according to Datalog’s rules. This component ensures the sequence of tokens conforms to the expected structure for the Datalog language, making the program interpretable by the Execution Engine.

### Interpreter
The **Interpreter** processes and executes the commands in the parsed Datalog program. It interacts with data structures based on the parsed input, outputting results or handling queries as defined by the program.

### File Structure
project-root/
│
├── Automata/                           # Contains automata classes for Lexer components
│   ├── AdditionAutomata.cpp            # Recognizes addition symbols in Datalog syntax
│   ├── AdditionAutomata.h
│   ├── ColonAutomaton.cpp              # Recognizes colon symbols
│   ├── ColonAutomaton.h
│   ├── ColonDashAutomaton.cpp          # Recognizes colon-dash symbols
│   ├── ColonDashAutomaton.h
│   ├── CommaAutomaton.cpp              # Recognizes comma symbols
│   ├── CommaAutomaton.h
│   ├── ...                             # (Other symbol recognizers follow similar patterns)
│   ├── IdentifierAutomaton.cpp         # Recognizes identifiers in Datalog syntax
│   ├── IdentifierAutomaton.h
│   └── StringAutomata.cpp              # Recognizes string literals
│
├── Datalog/                            # Handles Datalog program-specific logic and structure
│   ├── DatalogProgram.cpp              # Main logic for Datalog program handling
│   ├── DatalogProgram.h
│
├── Structures/                         # General data structures used in Datalog interpreter
│   ├── Relation.cpp                    # Defines relations (tables) used in Datalog
│   ├── Relation.h
│   ├── Tuple.cpp                       # Defines tuple structure for data storage within relations
│   ├── Tuple.h
│   ├── Predicate.cpp                   # Defines Datalog predicates (i.e., statements in the logic)
│   ├── Predicate.h
│   └── ...
│
├── Token/                              # Token management for Lexer components
│   ├── Token.cpp                       # Defines token structures, used to categorize parsed symbols
│   └── Token.h
│
├── lexer/                              # Core Lexer files, responsible for tokenizing Datalog programs
│   ├── Lexer.cpp                       # Main lexer logic for breaking down input into tokens
│   ├── Lexer.h
│
├── parser/                             # Contains parser logic, translates tokens into a structured program
│   ├── Parser.cpp                      # Manages syntax analysis of tokens
│   └── Parser.h
│
├── interpreter/                        # Interpreter or Execution engine
│   └── Interpreter.cpp                 # Main interpreter logic for executing parsed Datalog queries
│
├── main.cpp                            # Main entry point for running the Datalog interpreter
│
├── CMakeLists.txt                      # Build configuration for the project
│
├── README.md                           # Project overview and instructions for setup and usage
│
└── cmake-build-debug/                  # Generated build files (can be ignored or deleted if not using CMake)


