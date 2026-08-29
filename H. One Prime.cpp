#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}