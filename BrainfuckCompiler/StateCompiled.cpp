#include "StateCompiled.h"
class StateCompiled : public State {
public:
    void Compile(string input, Storage& storage_) override {

    }
    void Run() override {
        std::cout << "Running compiled program.\n";
    }
    void Clean() override {

    }
};