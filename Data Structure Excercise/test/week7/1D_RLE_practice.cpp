#include <iostream>
#include <vector>
using namespace std;

// [1] 압축 함수
vector<int> compress1D(const vector<int>& data) {
    //구현
}

// [2] 복원 함수
vector<int> decompress1D(const vector<int>& compressed) {
    //구현
}

// [3] 출력 함수
void printVector(const vector<int>& v, const string& title) {
    cout << "[" << title << "]" << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "배열 크기 입력: ";
    cin >> n;

    vector<int> data(n);
    cout << "배열 원소 입력 (0과 1로 구성): ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // [원본 출력]
    printVector(data, "원본 배열");

    // [압축]
    vector<int> compressed = compress1D(data);
    printVector(compressed, "압축 결과 ([횟수, 값] 순)");

    // [복원]
    vector<int> decompressed = decompress1D(compressed);
    printVector(decompressed, "복원 결과");

    return 0;
}
