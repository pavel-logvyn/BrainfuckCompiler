#pragma once
#include "libs.h"
class DecreaseIndex : public Operator {
private:
    Storage* storage_;
public:
    void Exec() const override;
    DecreaseIndex(Storage* storage);
};