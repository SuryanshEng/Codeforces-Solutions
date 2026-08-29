#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int x = A, y = B, z = C;

    if (x > y) swap(x, y);
    if (y > z) swap(y, z);
    if (x > y) swap(x, y);

    cout << x << '\n';
    cout << y << '\n';
    cout << z << '\n';

    cout << '\n';

    cout << A << '\n';
    cout << B << '\n';
    cout << C << '\n';

    return 0;
}