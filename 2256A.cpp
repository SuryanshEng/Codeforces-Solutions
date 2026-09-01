#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long v[3];
        cin >> v[0] >> v[1] >> v[2];
        sort(v,v+3);
        long long x = v[0];
        long long y = v[1];
        long long z = v[2];
        if(z > x + y){
            cout << y <<'\n';
        }
        else {
            cout << z - x << '\n';
        }
    }
    return 0;
}