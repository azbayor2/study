#include "set.cpp"

// --- is_disjoint 함수의 구현 ---
// bool Set::is_disjoint(Set& other) const {
//     for (int item : this->data) {
//         if (other.contains(item)) {
//             return false;
//         }
//     }
//     return true;
// }
// --- is_disjoint 함수의 구현 ---

// --- 테스트를 위한 main 함수 ---
int main() {
    Set set_A = {15982, 88234, 28371, 58291, 44092, 91234, 67321, 72345, 39871, 10293};
    Set set_B = {55290, 11983, 72845, 99182, 37261, 58291, 81734, 48261, 20394, 66582};
   //Set set_B = {10522, 21887, 34001, 49123, 75331, 61439, 79552, 88133, 93556, 54817}


    if (set_A.is_disjoint(set_B)) {
        cout << "두 집합은 서로소 관계임." << endl;
    } else {
        cout << "두 집합은 서로소 관계가 아님." << endl;
    }

    return 0;
}
// --- 테스트를 위한 main 함수 ---