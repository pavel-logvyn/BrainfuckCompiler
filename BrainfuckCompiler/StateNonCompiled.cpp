#include "StateNonCompiled.h"
class StateNonCompiled : public State {
public:
    void Compile(string input, Storage& storage_, list<Operator>& listOfOperations_) override {
        Compiler compiler(input, storage_, listOfOperations_);
        if(compiler.compile())
            context_->TransitionTo(new StateCompiled);
        else {
            cout << "Something went wrong. Check logs to see what happened.\n";
        }
    }
    void ReCompile(string input, Storage& storage_, list<Operator>& listOfOperations_) override {
        Compile(input, storage_, listOfOperations_);
    }
    void Run(list<Operator>& listOfOperations_) override {
        std::cout << "Can't run a non compiled program.\n";
    }
    void Clean(list<Operator>& listOfOperations_) override {
        std::cout << "Can't clean a non compiled program.\n";
    }
};