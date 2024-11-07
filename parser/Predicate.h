#ifndef PROJECT1_STARTER_CODE_PREDICATE_H
#define PROJECT1_STARTER_CODE_PREDICATE_H

#include "Parameter.h"
#include <string>
#include <vector>

class Predicate {
private:
    std::string ID;
    std::vector<Parameter*> parameterList;

public:
    Predicate() = default;
    ~Predicate() = default;
    void setID(std::string id);
    std::string getID() const;
    void setParameterList(std::vector<Parameter*> paramList);
    std::vector<Parameter*> getParameterList() const;
    std::string toString();
};

#endif //PROJECT1_STARTER_CODE_PREDICATE_H
