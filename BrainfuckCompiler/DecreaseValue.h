#pragma once
#include "libs.h"
class DecreaseValue : public Operator {
private:
    Storage* storage_;
public:
    void Exec() const override;
    DecreaseValue(Storage* storage);
};