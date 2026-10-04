#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> p(n), ans(n), used(n + 1);
        set<int> s;

        for (int &x : p) cin >> x;

        bool ok = true;

        for (int i = 0; i < n; ++i) {
            if (!i || p[i] != p[i - 1]) {
                if (p[i] > n || used[p[i]]) ok = false;
                else ans[i] = p[i], used[p[i]] = 1;
            }
        }

        for (int i = 1; i <= n; ++i)
            if (!used[i]) s.insert(i);

        for (int i = 0; i < n && ok; ++i) {
            if (!ans[i]) {
                auto it = s.begin();
                if (it == s.end() || *it > p[i]) ok = false;
                else ans[i] = *it, s.erase(it);
            }
        }

        if (!ok) cout << -1 << '\n';
        else {
            for (int x : ans) cout << x << ' ';
            cout << '\n';
        }
    }
}
