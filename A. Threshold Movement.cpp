#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> w(n + 1);
        for (int i = 1; i <= n; i++) cin >> w[i];

        if (n % 2 == 1) {
            cout << "NO\n";
            continue;
        }

        int L = -1e18, R = 1e18;
        for (int i = 1; i <= n; i += 2) {
            L = max(L, w[i + 1]);
            R = min(R, w[i]);
        }

        if (R - L >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}