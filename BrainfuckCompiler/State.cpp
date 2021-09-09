#include "State.h"
class State {
protected:
    Context* context_;
public:
    virtual ~State() {}
    void set_context(Context* context) {
        this->context_ = context;
    }
    virtual void Compile(string input, Storage& storage_, list<Operator>& listOfOperations_) = 0;
    virtual void ReCompile(string input, Storage& storage_, list<Operator>& listOfOperations_) = 0;
    virtual void Run(list<Operator>& listOfOperations_) = 0;
    virtual void Clean(list<Operator>& listOfOperations_) = 0;
};