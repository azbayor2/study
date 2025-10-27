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
    node(){
        next = NULL;
        data = 0;
    };

    private:
        node * next;
        value_type data;
};