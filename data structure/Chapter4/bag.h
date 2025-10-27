#pragma once
#include <cstdlib>
class bag{
    public:
    bag(const int & inits);
    bag(const bag & src);
    ~bag();
    void insert(int val);
    void remove(int val);
    size_t size() const;
    int occurrences(int target) const;
    //static const size_t CAP = 100;
    void operator+=(const bag & src);
    void operator=(const bag & src);
    void reserve(int new_cap);
    bag operator+(const bag &b1);

    private:
    int * data;
    size_t used;
    size_t CAP;
};