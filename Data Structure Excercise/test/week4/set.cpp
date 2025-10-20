#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Set {
private:
    using iterator = typename std::vector<int>::iterator;
    using const_iterator = typename std::vector<int>::const_iterator;
    std::vector<int> data;

public:
    Set();
    Set(std::initializer_list<int> init);

    void insert(int value);
    bool contains(int value);
    void erase(int value);

    bool is_disjoint(Set& other) const;

    iterator begin();
    iterator end();
    const_iterator find(const int& val);
    iterator lower_bound(iterator first, iterator last, const int& value) const;
};

Set::Set() {}

bool Set::is_disjoint(Set& other) const{
    for(int cur: this->data){
        if(other.contains(cur)) return false;
    }
    return true;
}

Set::Set(std::initializer_list<int> init) {
    for (const auto& elem : init) {
        insert(elem);
    }
}

void Set::insert(int value) {
    if (!contains(value)) {
        data.push_back(value);
        std::sort(data.begin(), data.end());
    }
}

bool Set::contains(int value) {
    return find(value) != end();
}

void Set::erase(int value) {
    auto it = std::find(data.begin(), data.end(), value);
    if (it != data.end()) {
        data.erase(it);
    }
}

Set::iterator Set::begin() {
    return data.begin();
}

Set::iterator Set::end() {
    return data.end();
}

Set::const_iterator Set::find(const int& val) {
    auto it = lower_bound(data.begin(), data.end(), val);
    if (it != data.end() && *it == val) {
        return it;
    }
    return data.end();
}

typename Set::iterator Set::lower_bound(iterator first, iterator last, const int& value) const {
    while (first < last) {
        iterator mid = first + (last - first) / 2;
        if (*mid < value) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
    return first;
}

int main() {
    Set set_A = {15982, 88234, 28371, 58291, 44092, 91234, 67321, 72345, 39871, 10293};
    //Set set_B = {55290, 11983, 72845, 99182, 37261, 58291, 81734, 48261, 20394, 66582};
    Set set_B = {10522, 21887, 34001, 49123, 75331, 61439, 79552, 88133, 93556, 54817};


    if (set_A.is_disjoint(set_B)) {
        cout << "두 집합은 서로소 관계임." << endl;
    } else {
        cout << "두 집합은 서로소 관계가 아님." << endl;
    }

    return 0;
}
