#pragma once

template<class Item>
class Table{
    public:

    static const int CAPACITY = 100;

    Table(){
        used= 0 ;
    }

    

    private:
    
    Item data[CAPACITY];
    std::size_t used;

    std::size_t hash(int key) const;
    int next_index(int index) const;
    bool find_index(int key, bool found, Item i);
    bool never_used(int index);
    bool is_vacant(int index);

    
};