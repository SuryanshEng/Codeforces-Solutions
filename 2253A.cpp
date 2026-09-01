#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAXN = 200000 + 5;
    vector<bool> isPrime(MAXN, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < MAXN; i++){
        if(isPrime[i]) {
            for(int j = i * i;j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (isPrime[n + 1] ? "YES" : "NO") << '\n';
    }
    return 0;
}