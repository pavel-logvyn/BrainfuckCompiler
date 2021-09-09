#pragma once
#include "libs.h"
class StateCompiled : public State {
public:
    void Compile(string input, Storage& storage_, list<Operator>& listOfOperations_) override;
    void ReCompile(string input, Storage& storage_, list<Operator>& listOfOperations_) override;
    void Run(list<Operator>& listOfOperations_) override;
    void Clean(list<Operator>& listOfOperations_) override;
};