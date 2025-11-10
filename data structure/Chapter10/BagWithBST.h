#include "BTreeNode.h"

template<class Item>
class Bag{
    private:
    binary_tree_node<Item> * headptr;
    size_t Size(const binary_tree_node<Item> * headptr);
    void insert_all(const binary_tree_node<Item> * src);

    public:
    Bag();
    ~Bag();
    Bag(const Bag & bg);
    void insert(const Item & data);
    void erase(const Item & data);
    void erase_one(const Item & data);
    void operator+=(const Bag & b);
    void operator=(const Bag & b);
    size_t size();
    size_t count(const Item & count);
    
};
