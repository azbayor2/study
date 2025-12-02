#pragma once
#include <iostream>

template<class Item, std::size_t SomePosNum>
class BTree{
    private:
    
    static const size_t MINIMUM = SomePosNum;
    static const size_t MAXIMUM = MINIMUM*2;

    size_t num_child;
    size_t num_data;

    Item data[MAXIMUM+1];
    BTree<Item, SomePosNum> * child[MAXIMUM+2];

    void middle_insert(size_t idx, const Item & t){

        if(num_data)
            for(size_t i = num_data-1; i>=idx; i--){
                data[i+1] = data[i];
            }

        data[idx] = t;
        num_data++;

        return;
    }

    void divide_node(size_t idx){
        BTree<Item, SomePosNum> * dest = child[idx];

        int mid = dest->num_data/2;
        middle_insert(idx, dest->data[mid]);

        BTree<Item, SomePosNum> * r = new BTree<Item, SomePosNum>();

        int new_data_count = (dest->num_data-1)/2;
        int new_child_count = (dest->num_child)/2;

        for(int i =0; i<new_data_count; i++){
            r->data[i] = dest->data[mid+1+i];
        }

        for(int i =0; i<new_child_count; i++){
            r->child[i] = dest->child[i+new_child_count];
        }
        
        dest->num_data = new_data_count;
        dest->num_child = new_child_count;
        r->num_data = new_data_count;
        r->num_child = new_child_count;

        if(num_child)
            for(size_t i = num_child-1; i>idx; i--)
                child[i+1] = child[i];
    
        child[idx+1] = r;

        num_child++;
        num_data++;

        return;
    }

    void remove_max(Item & rem){
        if(!num_child){
            num_child--;
            rem = data[num_child];
            return;
        }

        child[num_child-1]->remove_max(rem);

        return;

    }

    bool loose_insert(const Item & data){
        size_t idx=0;

        while(idx<num_data && this->data[idx]<data)
            idx++;

        if(idx<num_data && this->data[idx]==data) return false;

        //자식이 없을 때
        if(!num_child){
            middle_insert(idx, data);
            return true;
        }

        //자식이 있을 때

        if(!child[idx]->loose_insert(data)) return false;
        fix_excess(idx);

        return true;
    }

    void erase_middle(int idx){
        for(int i =idx; i<num_data-1; i++)
            data[i] = data[i+1];

        num_data--;

        return;
    }

    bool loose_erase(const Item & data){
        size_t idx = 0;
        while(idx<num_data && this->data[idx]<data)
            idx++;
        

        //자식이 없을 때
        if(!num_child){

            //목표값이 아니면
            if(idx>=num_data || this->data[idx]!=data)
                return false;

            //목표값이면
            if(idx<num_data && this->data[idx]==data){
                erase_middle(idx);
                return true;
            }
        }

        else{  //자식이 있을 때
            //목표값이 아니면
            if(idx>=num_data || this->data[idx]!=data){
                if(!this->child[idx]->loose_erase(data))
                    return false;
                fix_shortage(idx);

                return true;
            }

            else if(idx<num_data && this->data[idx]==data){  //목표값이면
                child[idx]->remove_max(this->data[idx]);
                fix_shortage(idx);

                return true;
            }
        }

        return false;
    }

    void merge_node(size_t idx){
        BTree<Item, SomePosNum> * lc = this->child[idx];
        BTree<Item, SomePosNum> * rc = this->child[idx+1];

        lc->middle_insert(lc->num_data, data[idx]);
        for(int i =0; i<rc->num_data; i++)
            lc->middle_insert(lc->num_data, rc->data[i]);

        for(int i =0; i<rc->num_child; i++){
            lc->child[i+lc->num_child] = rc->child[i];
            lc->num_child++;
        }

        rc->num_data=0;
        rc->num_child=0;

        for(int i = idx; i<num_data; i++)
            data[i] = data[i+1];
        
        for(int i =idx+1; i<num_child; i++)
            child[i] = child[i+1];

        num_child--;
        num_data--;

        delete rc;

        return;
    }

    bool fix_shortage(size_t idx){
        if(num_data>=MINIMUM) return false;

        //1. 왼쪽이 충분히 있을 때
        if(idx-1>=0 && child[idx-1]->num_count>MINIMUM){
            int l = idx-1;
            int r = idx;

            BTree<Item, SomePosNum> * lt = child[l];
            BTree<Item, SomePosNum> * rt = child[r];

            rt->middle_insert(0, data[l]); //rt에 루트 데이터 추가
            data[l] = lt->data[lt->num_data-1];  //lt에서 데이터 가져오기

            for(int i =rt->num_child-1; i>=0; i--)  //child 옮기기
                rt->child[i+1] = rt->child[i];
            rt->child[0] = lt->child[lt->num_child-1];

            lt->num_child--;
            lt->num_data--;
            rt->num_child++;
            
            return true;
        }

        //2. 오른쪽이 충분히 있을 때
        else if(idx+1<num_data && child[idx+1]->num_count>MINIMUM){

            int l = idx;
            int r = idx+1;

            BTree<Item, SomePosNum> * lt = child[l];
            BTree<Item, SomePosNum> * rt = child[r];

            lt->middle_insert(lt->num_child, data[l]);
            data[l] = lt->data[lt->num_data-1];

            lt->child[lt->num_child] = rt->child[0];

            for(int i =0; i<rt->num_child-1; i++)
                child[i] = child[i+1];
            
            lt->num_child++;
            rt->num_data--;
            rt->num_child--;

            return true;

        }


        //3. 왼쪽이 있을 때

        else if(idx-1>=0){
            merge_node(idx-1);
            return true;
        }


        //4. 오른쪽이 있을 때
        else{
            merge_node(idx);
            return true;
        }

        
        return false;
    }

    bool fix_excess(size_t idx){
        if(num_data<=MAXIMUM) return false;
        
        divide_node(idx);

        return true;
    }
    

    public:

    BTree(){
        num_child=0;
        num_data=0;
    }

    ~BTree(){
        for(int i=0; i<num_child; i++)
            delete child[i];
    }

    BTree(const BTree<Item, SomePosNum> & src){
        clear();

        for(int i =0; i<src.num_data; i++)
            data[i] = src.data[i];

        for(int i =0; i<src.num_child; i++)
            child[i] = new BTree(src.child[i]);

        num_data = src.num_data;
        num_child = src.num_child;
    }

    void operator=(const BTree & src){
        clear();

        for(int i =0; i<src.num_data; i++)
            data[i] = src.data[i];

        for(int i =0; i<src.num_child; i++)
            child[i] = new BTree(src.child[i]);

        num_data = src.num_data;
        num_child = src.num_child;

        return;
    }

    bool insert(const Item & data){
        if(!loose_insert(data)){
            return false;
        }

        if(num_data>MAXIMUM){

            BTree<Item, SomePosNum> * oldRoot = new BTree<Item, SomePosNum>();

            for(int i =0; i<num_data; i++)
                oldRoot->data[i] = this->data[i];

            for(int i =0; i<num_child; i++)
                oldRoot->child[i] = this->child[i];

            oldRoot->num_data = this->num_data;
            oldRoot->num_child = this-> num_child;

            this->num_data = 0;
            this->num_child = 1;
            child[0] = oldRoot;

            divide_node(0);
        }

        return true;
    }

    bool erase(const Item & data){
        if(!loose_erase(data)) return false;

        if(num_data==0){

            BTree<Item, SomePosNum> * delnode = child[0];

            for(int i =0; delnode->num_data; i++)
                data[i] = child[0]->data[i];

            for(int i=0; i<delnode->num_child; i++)
                child[i] = child[0]->child[i];

            delnode->num_child = 0;
            delnode->num_data = 0;

            delete delnode;
        }

        return true;
    }

    bool clear(){
        for(int i =0; i<num_child; i++){
            child[i]->clear();
            delete child[i];
        }
        num_child = 0;
        num_data = 0;

        return true;
    }

};