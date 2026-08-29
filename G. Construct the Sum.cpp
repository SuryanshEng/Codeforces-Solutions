#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        long long s;

        cin >> n >> s;

        long long maxSum = 1LL * n * (n + 1) / 2;

        if (s > maxSum)
        {
            cout << -1 << '\n';
            continue;
        }

        long long remaining = s;

        for (int x = n; x >= 1; x--)
        {
            if (x <= remaining)
            {
                cout << x << " ";
                remaining -= x;
            }

            if (remaining == 0)
            {
                break;
            }
        }

        cout << '\n';
    }

    return 0;
}
