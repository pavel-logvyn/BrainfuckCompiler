#include "IncreaseIndex.h"
class IncreaseIndex : public Operator {
private:
    Storage* storage_;
public:
    void Exec() const override {
        storage_->bfindex++;
    }
    IncreaseIndex(Storage* storage) :storage_(storage) {}
};