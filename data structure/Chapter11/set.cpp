#include "set.h"

template <class Item>
bool set<Item>::count(const Item & t){

    
}

template<class Item>
bool set<Item>::insert(const Item & t){
    //loost_insert시행
    //루트의 원소 개수가 초과되면 고치기
}


template<class Item>
bool set::loose_insert(const Item & t){
    //data[i]>= t 인 i 찾기
    //만약 data[i]==t이면 return false

    //만약 자식이 없으면 (말단노드이면) data[i]에 data 추가 후 return true;
    //자식이 있으면 set[i] 에 loose insert 후 fix_excess
}

template<class Item>
bool set::fix_excess(){
    //해당 노드의 데이터의 초과 현상을 고침
    //반으로 쪼갬
    //가운데 노드는 부모로 보냄
    //양 옆 노드는 부모의 자식으로 설정
}

template<class Item>
bool set::erase(const Item & t){
    //1. loose_erase 실행
    //2. 루트 노드가 shortage 현상이 있으면 고침

}

template<class Item>
bool set::loose_erase(const Item& t){
    //1. item[i]>=t 인 i 찾기
    //2. 자식이 없고 item[i]==t 이면 지우고 return true
    //3. 자식이 없고 item[i]!=t 이면 return false
    //4. 자식이 있으면
    // 4-1. loose_erase를 자식 노드에 대해서 수행
    // 4-2. fix_shortage를 자식 노드에 대해서 수행 

}

template<class Item>
bool set::fix_shortage(){


}
