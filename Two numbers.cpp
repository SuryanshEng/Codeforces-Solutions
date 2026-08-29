#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double A, B;
    cin >> A >> B;

    double x = A / B;

    cout << "floor " << A << " / " << B << " = " << floor(x) << '\n';
    cout << "ceil " << A << " / " << B << " = " << ceil(x) << '\n';
    cout << "round " << A << " / " << B << " = " << round(x) << '\n';

    return 0;
}