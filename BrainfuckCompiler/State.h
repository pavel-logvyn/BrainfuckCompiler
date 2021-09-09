#pragma once
#include "libs.h"
class State {
protected:
    Context* context_;
public:
    virtual ~State() {}
    void set_context(Context* context);
    virtual void Compile(string input, Storage& storage_, list<Operator> &listOfOperations_);
    virtual void ReCompile(string input, Storage& storage_, list<Operator>& listOfOperations_);
    virtual void Run(list<Operator>& listOfOperations_);
    virtual void Clean(list<Operator>& listOfOperations_);
};