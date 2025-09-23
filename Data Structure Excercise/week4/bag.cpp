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
    size_t count(const int& target) const;
    void find_most() const;

    int operator[](size_t i) const;
    void operator+=(const Bag& addend);

private:
    int data[CAPACITY];
    size_t used;
};

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

size_t Bag::count(const int &target) const{
    size_t ans =0;
    for(int i =0; i<used; i++){
        if(data[i]==target) ans++;
    }

    return ans;
}

void Bag::find_most() const{
    int temp, maxx=0;
    for(int i=0; i<used; i++)
    {
        int countt = count(data[i]);
        if(maxx< countt){
            maxx = countt; temp = data[i];
        }
    }

    cout << temp << " " << maxx << "\n";
    return;
}

int main() {
    Bag bag1;
    bag1.insert(1);
    bag1.insert(2);
    bag1.insert(1);

    cout << "bag1: ";
    for (size_t i = 0; i < bag1.size(); i++) {
        cout << bag1[i] << " ";
    }
    cout << endl << endl;

    Bag bag2;
    bag2.insert(4);
    bag2.insert(1);
    bag2.insert(6);

    cout << "bag2: ";
    for (size_t i = 0; i < bag2.size(); i++) {
        cout << bag2[i] << " ";
    }
    cout << endl << endl;

    bag2 += bag1;

    cout << "bag2: ";
    for (size_t i = 0; i < bag2.size(); i++) {
        cout << bag2[i] << " ";
    }

    //test

    cout << bag2.count(4) << "\n";
    
    cout << endl;

    return 0;
}
