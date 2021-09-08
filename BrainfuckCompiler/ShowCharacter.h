#pragma once
#include "libs.h"
class ShowCharacter : public Operator {
private:
    Storage* storage_;
public:
    void Exec() const override;
    ShowCharacter(Storage* storage);
};