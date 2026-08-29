#include <iostream>
using namespace std;

int main() {
    int A, B;
    char S;

    cin >> A >> S >> B;

    bool correct;

    if (S == '<')
        correct = A < B;
    else if (S == '>')
        correct = A > B;
    else
        correct = A == B;

    cout << (correct ? "Right" : "Wrong");

    return 0;
}