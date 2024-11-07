#ifndef PROJECT1_STARTER_CODE_PARSER_H
#define PROJECT1_STARTER_CODE_PARSER_H

#include "Token.h"
#include <vector>
#include <string>
#include "DatalogProgram.h"
#include "Predicate.h"

class Parser {
private:
    int index = 0;
    std::vector<Token*> tokenVector;
    DatalogProgram dlp;
    void schemeList(); // schemeList -> scheme schemeList | lambda
    void factList(); // factList -> fact factList | lambda
    void ruleList(); // ruleList -> rule ruleList | lambda
    void queryList(); // queryList	-> query queryList | lambda
    void scheme(); // scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
    void fact(); // fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    void rule(); // rule-> headPredicate COLON_DASH predicate predicateList PERIOD
    void query(); // query-> predicate Q_MARK
    void headPredicate(Predicate &headPred); // headPredicate -> ID LEFT_PAREN ID idList RIGHT_PAREN
    void predicate(Predicate &pred); // predicate -> ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    void predicateList(std::vector<Predicate> &bodyPredicates); // predicateList ->	COMMA predicate predicateList | lambda
    void parameterList(std::vector<Parameter*> &paramList); // parameterList -> COMMA parameter parameterList | lambda
    void stringList(std::vector<Parameter*> &paramList); // stringList -> COMMA STRING stringList | lambda
    void idList(std::vector<Parameter*> &paramList); // idList -> COMMA ID idList | lambda
    void parameter(); // parameter -> STRING | ID
    void eraseComments();

public:
    Parser() = default;
    Parser(std::vector<Token*> vectorOfTokens);
    ~Parser();
    void parse(); // datalogProgram -> SCHEMES COLON scheme schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList EOF
    void match(TokenType tok);
    DatalogProgram getDlp();
};

#endif //PROJECT1_STARTER_CODE_PARSER_H
