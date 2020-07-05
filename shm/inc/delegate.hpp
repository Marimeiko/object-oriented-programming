#pragma once

#include <cstddef>

class Delegate {
public:
    virtual ~Delegate() {}
    virtual void payCrew(size_t money) = 0;
};
