#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static constexpr int MAXX = 5;
static constexpr ll INF = (ll)4e18;

int n, q, X;

vector<int> d;
vector<ll> s;

struct Matrix {
    ll a[MAXX][MAXX];

    Matrix(bool identity = false) {
        for (int i = 0; i < MAXX; ++i)
            for (int j = 0; j < MAXX; ++j)
                a[i][j] = INF;

        if (identity) {
            for (int i = 0; i < X; ++i)
                a[i][i] = 0;
        }
    }
};

inline Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C;

    for (int i = 0; i < X; ++i) {
        for (int k = 0; k < X; ++k) {
            if (A.a[i][k] >= INF)
                continue;

            for (int j = 0; j < X; ++j) {
                if (B.a[k][j] >= INF)
                    continue;

                C.a[i][j] = min(C.a[i][j], A.a[i][k] + B.a[k][j]);
            }
        }
    }

    return C;
}

Matrix makePlatform(int len, ll cost) {
    Matrix M;

    for (int i = 0; i < X && i < len; ++i) {
        for (int j = 0; j < X; ++j) {
            ll distance = (ll)len + j - i;
            ll jumps = (distance + X - 1) / X;
            ll paidJumps = jumps - 1;

            M.a[i][j] = paidJumps * cost;
        }
    }

    return M;
}

vector<Matrix> seg;

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = makePlatform(d[l], s[l]);
        return;
    }

    int mid = (l + r) >> 1;

    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);

    seg[node] = multiply(seg[node << 1], seg[node << 1 | 1]);
}

void update(int node, int l, int r, int pos) {
    if (l == r) {
        seg[node] = makePlatform(d[l], s[l]);
        return;
    }

    int mid = (l + r) >> 1;

    if (pos <= mid)
        update(node << 1, l, mid, pos);
    else
        update(node << 1 | 1, mid + 1, r, pos);

    seg[node] = multiply(seg[node << 1], seg[node << 1 | 1]);
}

Matrix query(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return seg[node];

    int mid = (l + r) >> 1;

    if (qr <= mid)
        return query(node << 1, l, mid, ql, qr);

    if (ql > mid)
        return query(node << 1 | 1, mid + 1, r, ql, qr);

    Matrix left = query(node << 1, l, mid, ql, qr);
    Matrix right = query(node << 1 | 1, mid + 1, r, ql, qr);

    return multiply(left, right);
}

inline ll finishCost(int len, ll cost, int start) {
    if (start >= len)
        return INF;

    ll distance = (ll)len - 1 - start;
    ll jumps = (distance + X - 1) / X;

    return jumps * cost;
}

ll solveQuery(int l, int r) {
    if (l == r)
        return finishCost(d[l], s[l], 0);

    Matrix M = query(1, 0, n - 1, l, r - 1);

    ll answer = INF;

    for (int i = 0; i < X; ++i) {
        if (M.a[0][i] >= INF)
            continue;

        ll last = finishCost(d[r], s[r], i);

        if (last >= INF)
            continue;

        answer = min(answer, M.a[0][i] + last);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q >> X;

    d.resize(n);
    s.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> d[i];

    for (int i = 0; i < n; ++i)
        cin >> s[i];

    seg.resize(4 * n + 5);

    build(1, 0, n - 1);

    while (q--) {
        char type;
        cin >> type;

        if (type == '1') {
            int i, v;
            cin >> i >> v;
            --i;

            d[i] = v;
            update(1, 0, n - 1, i);
        }
        else if (type == '2') {
            int i;
            ll y;

            cin >> i >> y;
            --i;

            s[i] = y;
            update(1, 0, n - 1, i);
        }
        else {
            int l, r;
            cin >> l >> r;
            --l;
            --r;

            cout << solveQuery(l, r) << '\n';
        }
    }

    return 0;
}