#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> s;

    s.insert(1); s.insert(10);

    for(auto it=s.begin(); it!=s.end(); it++){
        cout << *it << " ";
    }

    s.erase(10);

    for(auto it=s.begin(); it!=s.end(); it++){
        cout << *it << " ";
    }

    return 0;
}