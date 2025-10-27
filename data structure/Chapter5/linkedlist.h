#pragma once
#include "node.h"

int length(const node * headptr);
void headinsert(node *& headptr, int data);
void insert(node * cur, int data);
void remove(node * cur);
void headremove(node *&headptr);
node * search(node * headptr, int data);
node * locate(node * headptr, const int & dest);
void listcopy(node *& headptr, node *& tailptr, const node * src);
void clear(const node * &headptr);