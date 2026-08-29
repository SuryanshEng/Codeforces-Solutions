#include <iostream>
using namespace std;

int main() {
    char X;
    cin >> X;

    if (X >= '0' && X <= '9') {
        cout << "IS DIGIT";
    }
    else {
        cout << "ALPHA\n";

        if (X >= 'A' && X <= 'Z')
            cout << "IS CAPITAL";
        else
            cout << "IS SMALL";
    }

    return 0;
}