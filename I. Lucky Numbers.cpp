#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int tens = n / 10;
    int ones = n % 10;

    if ((ones != 0 && tens % ones == 0) || ones % tens == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}