#include <list>
#include <iostream>

using namespace std;

int main(){
    list<int> l;

    l.push_back(1); l.push_back(2); l.push_back(10);

    auto it = l.begin();
    it++;
    it = l.erase(it);

    cout << *it << endl;

    return 0;
}