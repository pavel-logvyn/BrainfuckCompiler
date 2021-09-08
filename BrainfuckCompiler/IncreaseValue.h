#pragma once
#include "libs.h"
class IncreaseValue : public Operator {
private:
    Storage* storage_;
public:
    void Exec() const override;
    IncreaseValue(Storage* storage);
};