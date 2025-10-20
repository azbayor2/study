#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Bag {
public:
    static const size_t CAPACITY = 20;
    Bag() : used(0), data() { }

    void insert(const int& entry);
    bool erase_one(const int& target);
    size_t size() const;

    int operator[](size_t i) const;
    void operator+=(const Bag& addend);

    void find_most() const ;

    size_t count(const int&target)const;

private:
    int data[CAPACITY];
    size_t used;
};

inline void Bag::find_most() const{
    int count = 0;
    int cur = 0;

    for(int i =0; i<used; i++){
        if(count < this->count(data[i])){
            count = this->count(data[i]);
            cur = data[i];
        }
    }

    cout << "가장 많이 나온 과목 코드: " << cur << " 득표수: " << count << endl;
    return;
}

inline size_t Bag::count(const int&target)const{
    size_t ret = 0;
    for(int i =0; i<used; i++)
        if(data[i]==target) ret++;

    return ret;
}

inline void Bag::insert(const int& entry) {
    assert(size() < CAPACITY);
    data[used++] = entry;
}

inline bool Bag::erase_one(const int& target) {
    int index = 0;
    while ((index < used) && (data[index] != target))
        ++index;
    if (index == used)
        return false;
    --used;
    data[index] = data[used];
    return true;
}

size_t Bag::size() const {
    return used;
}

int Bag::operator[](size_t i) const {
    return data[i];
}

void Bag::operator+=(const Bag& addend) {
    assert(size() + addend.size() <= CAPACITY);
    copy(addend.data, addend.data + addend.used, data + used);
    used += addend.used;
}

int main() {
    Bag bag1;
    int N;
    cin >> N;
    int input;
    for(int i =0; i<N ;i++){
        cin >> input;
        bag1.insert(input);
    }

    bag1.find_most();

    return 0;
}
