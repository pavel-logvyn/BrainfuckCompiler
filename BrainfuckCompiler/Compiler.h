#pragma once
#include "libs.h"
class Compiler {
private:
    string input;
    Storage* storage_;
    list<Operator>* compiledProgram;
public:
    Compiler(string input_, Storage& storage, list<Operator>& listOfOperations);
    ~Compiler();
    bool compile();
};