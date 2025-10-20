#pragma once
#include <cstdlib>
class bag{
    public:
    bag();
    void insert(int val);
    void remove(int val);
    size_t size() const;
    int occurrences(int target) const;
    static const size_t CAP = 100;

    private:
    int data[CAP];
    size_t used;
};