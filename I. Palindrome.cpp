#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;

    reverse(n.begin(), n.end());

    int i = 0;
    while (i < n.size() - 1 && n[i] == '0') i++;

    for (; i < n.size(); i++) cout << n[i];
    cout << '\n';

    string r = n;
    reverse(r.begin(), r.end());

    cout << (r == n ? "YES" : "NO");

    return 0;
}