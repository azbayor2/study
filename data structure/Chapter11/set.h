#pragma once

template<class Item>
class set{
    private:

    static const size_t MINIMUM = 200;
    static const size_t MAXIMUM = MINIMUM*2;
    size_t data_count;
    Item data[MAXIMUM+1];
    size_t child_count;
    set* subset[MAXIMUM+2];


    public:

    bool count(const Item & t);
    void 
    
};