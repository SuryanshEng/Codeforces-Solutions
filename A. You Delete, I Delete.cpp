#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string ans;
        bool skipped0 = false, skipped1 = false;
        for (char c : s) {          
            if (!skipped0 && c == '0') {
                skipped0 = true;
                continue;
            }
            if (!skipped1 && c == '1') {
                skipped1 = true;
                continue;
            }
            ans.push_back(c);
        }
        cout << ans << '\n';
    }
    return 0;
}