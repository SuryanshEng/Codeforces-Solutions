#include <bits/stdc++.h>
using namespace std;

int main() {
    double X, P;
    cin >> X >> P;

    double original = P / (1.0 - X / 100.0);

    // Round up to 2 decimal places
    original = ceil(original * 100.0 - 1e-9) / 100.0;

    cout << fixed << setprecision(2) << original << '\n';

    return 0;
}