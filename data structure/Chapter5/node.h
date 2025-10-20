#pragma once
#include <iterator>

typedef int value_type;

class node{
    public:
    void set_link(node * next);
    void set_data(const value_type & data);
    value_type get_data() const;
    const node* get_link() const;
    node *get_link();
    node(value_type & init_data, node *init_link=nullptr);

    private:
        node * next;
        value_type data;
};

class node_iterator: public std::iterator<std::forward