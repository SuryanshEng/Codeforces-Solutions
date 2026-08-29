#include <iostream>
using namespace std;

int main() {
    long long n, k, a;
    cin >> n >> k >> a;

    long long product = n * k;

    if (product % a != 0)
        cout << "double";
    else if (product / a <= 2147483647)
        cout << "int";
    else
        cout << "long long";

    return 0;
}