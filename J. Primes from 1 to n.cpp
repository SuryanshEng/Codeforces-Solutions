#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int x = 2; x <= n; x++) {
        bool prime = true;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0) prime = false;

        if (prime) cout << x << ' ';
    }

    return 0;
}