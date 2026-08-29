#include <bits/stdc++.h>
using namespace std;

int main() {
    double X, P;
    cin >> X >> P;

    double original = (P * 100) / (100 - X);

    cout << fixed << setprecision(2) << original << '\n';

    return 0;
}