#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long maximum = 0;

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;

        if (x > maximum)
            maximum = x;
    }

    cout << maximum << endl;

    return 0;
}