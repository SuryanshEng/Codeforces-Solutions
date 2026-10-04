#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    string s;
    cin >> n >> k >> s;

    int cnt[26] = {};
    for (char c : s) cnt[c - 'A']++;
    sort(cnt, cnt + 26, greater<int>());

    long long ans = 0;
    for (int i = 0; i < 26 && k > 0; i++) {
        long long take = min(cnt[i], k);
        ans += take * take;
        k -= take;
    }
    cout << ans << "\n";
    return 0;
}
