#include <iostream>
#include <list>
using namespace std;

void removeDuplicates(list<int>& L) {
    auto t = L.begin();
    while(t!=L.end()){
        auto search = L.begin();
        while(search!=t){
            if(*search == *t){
                t = L.erase(t);
                break;
            }
            search++;
        }
        t++;
    }

}

int main() {
    list<int> nums = {3, 1, 3, 2, 2, 4, 3};

    cout << "[원본 리스트]" << endl;
    for (int x : nums) cout << x << " ";
    cout << endl;

    removeDuplicates(nums);

    cout << "\n[중복 제거 후]" << endl;
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}
