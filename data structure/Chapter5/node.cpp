#include "node.h"


node::node(value_type & init_data, node *init_link){
    data = init_data;
    next = init_link;
}


void node::set_link(node * next){
    this->next = next;
}

void node::set_data(const value_type & data){
    this->data = data;
}

value_type node::get_data() const{
    return data;
}

const node* node::get_link() const{
    const node * ret = next;
    return ret;
}
node* node::get_link(){
    return next;
}