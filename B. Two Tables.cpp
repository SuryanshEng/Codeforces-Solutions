#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int na, ma, nb, mb;
    cin >> na >> ma;
    vector<string> a(na);
    for (auto &r : a) cin >> r;
    cin >> nb >> mb;
    vector<string> b(nb);
    for (auto &r : b) cin >> r;

    int best = -1, bx = 0, by = 0;
    for (int x = -na; x <= nb; x++) {
        for (int y = -ma; y <= mb; y++) {
            int cur = 0;
            for (int i = max(0, -x); i < na && i + x < nb; i++)
                for (int j = max(0, -y); j < ma && j + y < mb; j++)
                    cur += (a[i][j] & b[i + x][j + y] & 1);
            if (cur > best) best = cur, bx = x, by = y;
        }
    }
    cout << bx << " " << by << "\n";
    return 0;
}
