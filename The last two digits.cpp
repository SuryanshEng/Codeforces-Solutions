#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    long long ans = ((A % 100) * (B % 100) % 100);
    ans = (ans * (C % 100)) % 100;
    ans = (ans * (D % 100)) % 100;

    cout << setw(2) << setfill('0') << ans << '\n';

    return 0;
}