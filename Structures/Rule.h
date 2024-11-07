#ifndef PROJECT1_STARTER_CODE_RULE_H
#define PROJECT1_STARTER_CODE_RULE_H

#include "Structures/Predicate.h"
#include <vector>
#include <string>

class Rule {
private:
    Predicate headPredicate;
    std::vector<Predicate> bodyPredicates;

public:
    Rule() = default;
    ~Rule() = default;
    void setHeadPredicate(const Predicate& headPred);
    void setBodyPredicates(std::vector<Predicate> bodyPredicate);
    Predicate getHeadPredicate();
    std::vector<Predicate> getBodyPredicates();
    std::string toString();
};

#endif //PROJECT1_STARTER_CODE_RULE_H
