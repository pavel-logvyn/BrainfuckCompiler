#pragma once
#include "libs.h"
class StateNonCompiled : public State {
public:
    void Compile(string input, Storage& storage_) override;
    void Run() override;
    void Clean() override;
};