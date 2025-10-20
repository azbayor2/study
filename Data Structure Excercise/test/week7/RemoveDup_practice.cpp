#include <iostream>
#include <list>
using namespace std;

void removeDuplicates(list<int>& L) {
    for (auto it = L.begin(); it != L.end(); ++it) {
        auto nextIt = it;
        nextIt++;
        while(nextIt!=L.end()){
            if(*nextIt==*it){
                nextIt = L.erase(nextIt);
            } else nextIt++;
        }
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
