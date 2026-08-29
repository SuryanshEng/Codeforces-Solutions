#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int X,Y;
        cin >> X >> Y;
        int start = min(X,Y);
        int end = max(X,Y);
        int sum = 0;
        for(int i = start+1;i < end;i++){
            if(i % 2 != 0){
                sum += i;
            }
        }
        cout << sum << '\n';
    }
   
    return 0;
}