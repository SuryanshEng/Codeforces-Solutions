#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;

    long double left = B * log((long double)A);
    long double right = D * log((long double)C);

    if (left > right)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}