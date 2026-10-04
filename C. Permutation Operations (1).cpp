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
        vector<int> x(n + 1);
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            x[a] = (i < n) ? i + 1 : 1;
        }
        for (int i = 1; i <= n; i++) cout << x[i] << " \n"[i == n];
    }
    return 0;
}
