#include "Context.h"
class Context {
private:
    State* state_;
    Storage* storage_ = new Storage();
    list<Operator>* listOfOperations = new list<Operator>;
public:
    Context(State* state) : state_(nullptr) {
        this->TransitionTo(state);
    }
    ~Context() {
        delete state_;
        delete storage_;
        delete listOfOperations;
    }
    void TransitionTo(State* state) {
#ifdef _DEBUG
        std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
#endif
        if (this->state_ != nullptr) {
            delete this->state_;
        }
        this->state_ = state;
        this->state_->set_context(this);
    }
    void RequestCompile(string input) {
        this->state_->Compile(input, *storage_, *listOfOperations);
    }
    void RequestRun() {
        this->state_->Run(*listOfOperations);
    }
    void RequestClean() {
        this->state_->Clean(*listOfOperations);
    }
};