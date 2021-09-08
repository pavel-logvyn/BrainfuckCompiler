#include "OpenLoopBracket.h"
class OpenLoopBracket : public Operator {
private:
    Storage* storage_;
public:
    //do nothing
    void Exec() const override {
    }
    OpenLoopBracket(Storage* storage, string input, int& i) :storage_(storage) {

    }
};