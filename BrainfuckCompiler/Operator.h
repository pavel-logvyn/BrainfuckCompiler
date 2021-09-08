#pragma once
class Operator {
public:
    virtual ~Operator() {}
    virtual void Exec() const = 0;
};