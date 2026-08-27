#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int count = 0;

        while (N > 0) {
            if (N % 2 == 1) {
                count++;
            }
            N /= 2;
        }

        int answer = 0;

        for (int i = 0; i < count; i++) {
            answer = answer * 2 + 1;
        }

        cout << answer << '\n';
    }

    return 0;
}