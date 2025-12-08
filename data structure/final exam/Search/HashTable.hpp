#pragma once
#include <cassert>

typedef struct _item{
    int key;
    int val1;
    int val2;
} item;


template <class Item>
class HashTable{
    private:
    static const int MAX = 1000;
    static const int NEVER_USED = -1;
    static const int PREV_USED = -2;

    Item data[MAX];
    int data_count;

    int hash(int key){
        return key%MAX;
    }

    int next_index(int idx){
        return (idx+1)%MAX;
    }

    bool never_used(int idx){
        return data[idx].key==NEVER_USED;
    }

    bool is_vacant(int idx){
        return (data[idx].key<0);
    }

    void find_index(int key, bool &found, int &idx){
        int cur_idx = hash(key);

        int count = 0;
        while(count<MAX && !never_used(cur_idx) && data[cur_idx].key!=key){
            cur_idx = next_index(cur_idx);
            count++;
        }

        if(data[cur_idx].key == key){
            found = 1;
            idx = cur_idx;
            return;
        }

        found = 0;
        return;
    }

    public:

    HashTable(){
        data_count=0;
        for(int i =0; i<MAX; i++)
            data[i].key = NEVER_USED;
    }
    

    bool insert(const Item ins){
        assert(data_count<MAX);
        bool found;
        int idx;
        
        find_index(ins.key, found, idx);
        if(found) return false;

        idx = hash(ins.key);

        while(!is_vacant(idx))
            idx = next_index(idx);

        data[idx] = ins;
        data_count++;

        return true;
    }

    bool erase(int key){
        bool found;
        int idx;

        find_index(key, found, idx);

        if(found){
            data[idx].key = PREV_USED;
            data_count--;
            return true;
        }

        return false;
    }

};