#include "StateCompiled.h"
class StateCompiled : public State {
public:
    void Compile(string input, Storage& storage_, list<Operator>& listOfOperations_) override {
        Compiler compiler(input, storage_, listOfOperations_);
        if (!compiler.compile())
            context_->TransitionTo(new StateCompiled);
        else {
            cout << "Something went wrong. Check logs to see what happened.\n";
        }
    }
    void ReCompile(string input, Storage& storage_, list<Operator>& listOfOperations_) override {
        Compile(input, storage_, listOfOperations_);
    }
    void Run(list<Operator>& listOfOperations_) override {
        context_->TransitionTo(new StateRunning);
        context_->RequestRun();
    }
    void Clean(list<Operator>& listOfOperations_) override {
        delete &listOfOperations_;
        listOfOperations_ = list<Operator>();
#ifdef _DEBUG
        cout << "Solution was cleared.\n";
#endif
        context_->TransitionTo(new StateNonCompiled);
    }
};