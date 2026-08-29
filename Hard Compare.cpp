#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    __int128 left = (__int128)A * B;
    __int128 right = (__int128)C * D;

    if (left > right)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}