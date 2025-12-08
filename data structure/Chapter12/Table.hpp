#pragma once

typedef struct _SomeData{
    int key;
    int value1;
    int value2;

    bool operator==(_SomeData & cmp){
        return this->key==cmp.key;
    }
} SomeData;

template<class Item>
class Table{
    public:

    static const int CAPACITY = 100;

    private:
    
    Item data[CAPACITY];
    static const int NEVER_USED=-1;
    static const int PREVIOUSLY_USED=-2;
    std::size_t used;

    std::size_t hash(int key) const{
        return key%100;
    }

    int next_index(int index) const{
        return (index+1)%CAPACITY;
    }

    bool find_index(int key, bool & found, int & i){
        int idx = hash(key);
        int count=0;
        while(count<CAPACITY && !never_used(idx) && this->data[idx].key!=key){
            count++;
            idx = next_index(idx);
        }

        if(this->data[idx].key!=key){
            found = 0;
            return false;
        }

        found = 1;
        i = idx;
        return true;

    }

    bool never_used(int index){
        return data[index].key==NEVER_USED;
    }

    bool is_vacant(int index){
        return (data[index].key==PREVIOUSLY_USED || data[index].key==NEVER_USED);
    }

    public:

    Table(){
        used= 0;
        for(int i =0; i<CAPACITY; i++)
            data[i].key = NEVER_USED;
    }

    bool insert(Item data){
        bool found;
        int idx;

        find_index(data.key, found, idx);
        if(found) return false;

        idx = hash(data.key);

        int count=0;
        while(count<CAPACITY && !is_vacant(idx)){
            if(this->data[idx]==data) return false;
            idx = next_index(idx);
            count++;
        }

        this->data[idx] = data;
        used++;
        return true;
    }

    bool erase(int key){
        bool found;
        int idx;
        find_index(key, found, idx);

        if(!found) return false;
        this->data[idx].key = PREVIOUSLY_USED;
        used--;

        return true;
    }

    
};