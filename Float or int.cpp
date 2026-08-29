#include <iostream>
using namespace std;

int main() {
    double N;
    cin >> N;

    int integerPart = (int)N;
    double decimalPart = N - integerPart;

    if (decimalPart == 0)
        cout << "int " << integerPart;
    else
        cout << "float " << integerPart << " " << decimalPart;

    return 0;
}