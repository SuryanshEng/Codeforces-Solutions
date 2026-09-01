#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int freq[1001] = {0};
        long long total = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
            freq[a[i]]++;
        }

        int max_freq = 0;
        int max_value = 0;
        for (int val = 1; val <= 1000; val++) {
            if (freq[val] > max_freq) {
                max_freq = freq[val];
                max_value = val;
            }
        }

        if (max_freq <= (n + 1) / 2) {
            cout << total << '\n';
        } else {
            int other_count = n - max_freq;
            long long sum_other = total - 1LL * max_freq * max_value;
            long long ans = sum_other + 1LL * (other_count + 2) * max_value;
            cout << ans << '\n';
        }
    }

    return 0;
}