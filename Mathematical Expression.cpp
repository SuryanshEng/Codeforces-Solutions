#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    char S, Q;

    cin >> A >> S >> B >> Q >> C;

    int result;

    if (S == '+')
        result = A + B;
    else if (S == '-')
        result = A - B;
    else
        result = A * B;

    if (result == C)
        cout << "Yes";
    else
        cout << result;

    return 0;
}