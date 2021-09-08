#include "ShowCharacter.h"
class ShowCharacter : public Operator {
private:
    Storage* storage_;
public:
    void Exec() const override {
        cout << storage_->bfstorage[storage_->bfindex];
    }
    ShowCharacter(Storage* storage) :storage_(storage) {}
};