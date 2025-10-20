#include <iostream>
#include <vector>
using namespace std;

// [1] 압축 함수
vector<int> compress1D(const vector<int>& data) {
    vector<int> ret;
    int count=1;
    for(int i =0; i<data.size(); i++){
        if((i+1)<data.size() && data[i]==data[i+1]){
            count++;
            continue;
        }

        ret.push_back(count);
        ret.push_back(data[i]);
        count=1;
    }

    return ret;
}

// [2] 복원 함수
vector<int> decompress1D(const vector<int>& compressed) { 
    vector<int> ret;
    for(int i =0; i<compressed.size(); i+=2){
        for(int j=0; j<compressed[i]; j++)
            ret.push_back(compressed[i+1]);
    }

    return ret;
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
