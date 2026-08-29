#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    while(cin >> N >> M){
        if(N <= 0 || M <= 0){
            break;
        }
        int start = min(N,M);
        int end = max(N,M);
        int sum = 0;
        for(int i = start; i <= end;i++){
            cout << i <<" ";
            sum += i;
        }
        cout << "sum =" << sum << '\n';
    }
    return 0;
}