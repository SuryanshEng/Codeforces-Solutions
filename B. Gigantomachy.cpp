#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        long long a0, b0;

        cin >> a0;
        for (int i = 1; i < n; i++) {
            long long x;
            cin >> x;
        }

        cin >> b0;
        for (int i = 1; i < m; i++) {
            long long x;
            cin >> x;
        }

        long long bea = a0 + n - 1;
        long long ver = b0 + m - 1;

        if (bea >= ver)
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }

    return 0;
}
