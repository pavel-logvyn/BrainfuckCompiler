#pragma once
#include "libs.h"
class StateRunning : public State {
public:
    void Compile(string input, Storage& storage_) override;
    void Run() override;
    void Clean() override;
};