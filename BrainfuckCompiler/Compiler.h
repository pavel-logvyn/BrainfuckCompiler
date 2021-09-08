#pragma once
#include "libs.h"
class Compiler {
private:
    string input;
    Storage* storage_;
    queue<Operator> compiledProgram;
public:
    Compiler(string input_, Storage& storage) : input(input_), storage_(&storage) {}
    void compile();
};