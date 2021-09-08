#include "IncreaseValue.h"
class IncreaseValue : public Operator {
private:
    Storage* storage_;
public:
    void Exec() const override {
        storage_->bfstorage[storage_->bfindex]++;
    }
    IncreaseValue(Storage* storage) :storage_(storage) {}
};