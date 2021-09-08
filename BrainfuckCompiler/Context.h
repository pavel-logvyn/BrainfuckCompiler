#pragma once
#include "libs.h"
class Context {
private:
    State* state_;
    Storage* storage_;
public:
    Context(State* state);
    ~Context();
    void TransitionTo(State* state);
    void RequestCompile(string input);
    void RequestRun();
    void RequestClean();
};