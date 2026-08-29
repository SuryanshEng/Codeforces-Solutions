#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int even = 0, odd = 0, positive = 0, negative = 0;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x % 2 == 0)
            even++;
        else
            odd++;

        if (x > 0)
            positive++;
        else if (x < 0)
            negative++;
    }

    cout << "Even: " << even << endl;
    cout << "Odd: " << odd << endl;
    cout << "Positive: " << positive << endl;
    cout << "Negative: " << negative << endl;

    return 0;
}