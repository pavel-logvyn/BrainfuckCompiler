#include "DecreaseValue.h"
class DecreaseValue : public Operator {
private:
    Storage* storage_;
public:
    void Exec() const override {
        storage_->bfstorage[storage_->bfindex]--;
    }
    DecreaseValue(Storage* storage) :storage_(storage) {}
};