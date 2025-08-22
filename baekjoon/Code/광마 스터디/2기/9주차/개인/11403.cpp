#include <iostream>
using namespace std;

int arr[101][101], N;

bool mult(){
    int arr_t[101][101] = {{0,},};
    bool updated=0;
    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++){
            int temp = 0;
            for(int k=0; k<N; k++) 
                temp+=arr[i][k]*arr[k][j];
            if(temp>0 && arr[i][j]==0) updated=1;
            arr_t[i][j] = (temp==0 ? 0:1);
        }
    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++){
            arr[i][j] = max(arr[i][j], arr_t[i][j]);
        }
    return updated;
}

int main(){
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++)
            cin >> arr[i][j];
    while(1){
        if(!mult()) break;
    }
    
    for(int i =0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    
    return 0;
}