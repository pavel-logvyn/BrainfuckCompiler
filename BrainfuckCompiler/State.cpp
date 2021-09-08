#include "State.h"
class State {
protected:
    Context* context_;
public:
    virtual ~State() {}
    void set_context(Context* context) {
        this->context_ = context;
    }
    virtual void Compile(string input, Storage& storage_) = 0;
    virtual void Run() = 0;
    virtual void Clean() = 0;
};