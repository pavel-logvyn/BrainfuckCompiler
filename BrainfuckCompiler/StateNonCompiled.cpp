#include "StateNonCompiled.h"
class StateNonCompiled : public State {
public:
    void Compile(string input, Storage& storage_) override {
        Compiler compiler(input, storage_);
        context_->TransitionTo(new StateCompiled);
    }
    void Run() override {
        std::cout << "Can't run a non compiled program.\n";
    }
    void Clean() override {
        std::cout << "Can't clean a non compiled program.\n";
    }
};