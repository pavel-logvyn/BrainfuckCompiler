#pragma once
#include "libs.h"
class IncreaseIndex : public Operator {
private:
    Storage* storage_;
public:
    void Exec() const override;
    IncreaseIndex(Storage* storage);
};