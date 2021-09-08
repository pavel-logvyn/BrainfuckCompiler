#include "DecreaseIndex.h"
class DecreaseIndex : public Operator {
private:
    Storage* storage_;
public:
    void Exec() const override {
        storage_->bfindex--;
    }
    DecreaseIndex(Storage* storage) :storage_(storage) {}
};