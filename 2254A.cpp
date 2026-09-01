#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long v[3];
        cin >> v[0] >> v[1] >> v[2];

        sort(v, v + 3);

        long long ans = min(v[1] - v[0], v[2] - v[1]);
        cout << ans << '\n';
    }

    return 0;
}