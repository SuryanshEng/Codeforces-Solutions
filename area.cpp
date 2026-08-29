#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double R;
    cin >> R;

    const double PI = 3.141592653;

    cout << fixed << setprecision(9) << PI * R * R;

    return 0;
}