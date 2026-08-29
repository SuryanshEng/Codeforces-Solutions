#include <iostream>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        long long L,R;
        cin >> L >> R;
        if(L > R){
            swap(L,R);
        }
        long long ans = R * (R + 1) / 2 - (L - 1) * L / 2;
        cout << ans << '\n';
    }
    return 0;
}