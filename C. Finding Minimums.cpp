#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long mn = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        mn = min(mn, x);

        if ((i + 1) % k == 0) {
            cout << mn << " ";
            mn = LLONG_MAX;
        }
    }

    if (n % k != 0)
        cout << mn << " ";

    return 0;
}
