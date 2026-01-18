#include <iostream>
#include <algorithm>

using namespace std;

int cache[5001][5001], N, arr[5001];

int find_palindrome(int s, int e){
    if(s>e) return 0;

    if(cache[s][e]!=-1) return cache[s][e];

    if(s==e) return cache[s][e]=0;

    if(arr[s]==arr[e]) return cache[s][e] = find_palindrome(s+1, e-1);

    return cache[s][e] = min(find_palindrome(s, e-1), find_palindrome(s+1, e))+1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    
    for(int i =0; i<N; i++) cin >> arr[i];
    for(int i =0; i<5001; i++)
        fill(cache[i], cache[i]+5001, -1);

    cout << find_palindrome(0, N-1) << "\n";

    return 0;

}