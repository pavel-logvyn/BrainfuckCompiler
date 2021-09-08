#include "Context.h"
class Context {
private:
    State* state_;
    Storage* storage_;
public:
    Context(State* state) : state_(nullptr) {
        this->TransitionTo(state);
    }
    ~Context() {
        delete state_;
        delete storage_;
    }
    void TransitionTo(State* state) {
        std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
        if (this->state_ != nullptr) {
            delete this->state_;
        }
        this->state_ = state;
        this->state_->set_context(this);
    }
    void RequestCompile(string input) {
        this->state_->Compile(input, *storage_);
    }
    void RequestRun() {
        this->state_->Run();
    }
    void RequestClean() {
        this->state_->Clean();
    }
};