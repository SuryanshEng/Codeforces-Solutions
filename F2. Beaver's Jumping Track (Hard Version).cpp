#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int MX = 10, BS = 16;
constexpr ll INF = (ll)4e18;

int X;

struct Mat {
    ll a[MX * MX];
    Mat(ll v = INF) { fill(a, a + MX * MX, v); }
    ll& operator()(int i, int j) { return a[i * X + j]; }
    const ll& operator()(int i, int j) const { return a[i * X + j]; }
};

Mat I() {
    Mat m;
    for (int i = 0; i < X; ++i) m(i, i) = 0;
    return m;
}

inline Mat mul(const Mat& A, const Mat& B) {
    Mat C;
    for (int i = 0; i < X; ++i)
        for (int k = 0; k < X; ++k) {
            ll v = A(i, k);
            if (v == INF) continue;
            const ll* b = B.a + k * X;
            ll* c = C.a + i * X;
            for (int j = 0; j < X; ++j)
                if (b[j] != INF)
                    c[j] = min(c[j], v + b[j]);
        }
    return C;
}

inline Mat addPlatform(const Mat& A, int d, ll s) {
    Mat C;

    for (int i = 0; i < X; ++i) {
        ll pre[MX + 1], suf[MX + 1];
        pre[0] = INF;
        for (int k = 0; k < X; ++k)
            pre[k + 1] = min(pre[k], A(i, k));

        suf[X] = INF;
        for (int k = X - 1; k >= 0; --k)
            suf[k] = min(suf[k + 1], A(i, k));

        for (int j = 0; j < X; ++j) {
            int t = d - X + 1 + j;

            if (t <= 0) {
                C(i, j) = A(i, t + X - 1);
                continue;
            }

            int z = d + j - X;
            int q = z / X, r = z % X;

            if (r)
                C(i, j) = pre[r] == INF ? INF : pre[r] + 1LL * (q + 1) * s;

            if (suf[r] != INF)
                C(i, j) = min(C(i, j), suf[r] + 1LL * q * s);
        }
    }

    return C;
}

inline void applyPlatform(
    ll st[MX], int d, ll s, ll out[MX]
) {
    ll pre[MX + 1], suf[MX + 1];

    pre[0] = INF;
    for (int k = 0; k < X; ++k)
        pre[k + 1] = min(pre[k], st[k]);

    suf[X] = INF;
    for (int k = X - 1; k >= 0; --k)
        suf[k] = min(suf[k + 1], st[k]);

    for (int j = 0; j < X; ++j) {
        int t = d - X + 1 + j;

        if (t <= 0) {
            out[j] = st[t + X - 1];
            continue;
        }

        int z = d + j - X;
        int q = z / X, r = z % X;

        ll v = INF;

        if (r && pre[r] != INF)
            v = pre[r] + 1LL * (q + 1) * s;

        if (suf[r] != INF)
            v = min(v, suf[r] + 1LL * q * s);

        out[j] = v;
    }
}

inline void applyMat(
    ll st[MX], const Mat& M, ll out[MX]
) {
    fill(out, out + X, INF);

    for (int i = 0; i < X; ++i) {
        if (st[i] == INF) continue;

        const ll* row = M.a + i * X;

        for (int j = 0; j < X; ++j)
            if (row[j] != INF)
                out[j] = min(out[j], st[i] + row[j]);
    }
}

struct SegTree {
    int S, nb;
    vector<Mat> tr;
    vector<int>& d;
    vector<ll>& s;

    SegTree(vector<int>& d_, vector<ll>& s_)
        : d(d_), s(s_) {
        nb = (int(d.size()) + BS - 1) / BS;
        S = 1;
        while (S < nb) S <<= 1;

        tr.resize(S << 1);
        Mat id = I();
        for (auto& m : tr) m = id;

        for (int b = 0; b < nb; ++b) rebuild(b);

        for (int p = S - 1; p; --p)
            tr[p] = mul(tr[p << 1], tr[p << 1 | 1]);
    }

    void rebuild(int b) {
        Mat cur = I();
        int l = b * BS;
        int r = min((int)d.size(), l + BS);

        for (int i = l; i < r; ++i)
            cur = addPlatform(cur, d[i], s[i]);

        tr[S + b] = cur;
    }

    void update(int p) {
        int b = p / BS;
        rebuild(b);

        for (int v = (S + b) >> 1; v; v >>= 1)
            tr[v] = mul(tr[v << 1], tr[v << 1 | 1]);
    }

    void queryBlocks(
        int l, int r, ll st[MX]
    ) const {
        int L[32], R[32], lc = 0, rc = 0;

        l += S;
        r += S;

        while (l < r) {
            if (l & 1) L[lc++] = l++;
            if (r & 1) R[rc++] = --r;
            l >>= 1;
            r >>= 1;
        }

        ll tmp[MX];

        for (int z = 0; z < lc; ++z) {
            applyMat(st, tr[L[z]], tmp);
            memcpy(st, tmp, X * sizeof(ll));
        }

        while (rc--) {
            applyMat(st, tr[R[rc]], tmp);
            memcpy(st, tmp, X * sizeof(ll));
        }
    }
};

ll solve(
    int l, int r,
    const vector<int>& d,
    const vector<ll>& s,
    const SegTree& seg
) {
    ll st[MX], tmp[MX];
    fill(st, st + X, INF);

    for (int j = 0; j < X; ++j) {
        int t = d[l] - X + 1 + j;
        if (t >= 1)
            st[j] = 1LL * ((t - 1 + X - 1) / X) * s[l];
    }

    int p = l + 1;

    while (p <= r && p % BS) {
        applyPlatform(st, d[p], s[p], tmp);
        memcpy(st, tmp, X * sizeof(ll));
        ++p;
    }

    int bl = p / BS;
    int br = (r + 1) / BS;

    if (bl < br) {
        seg.queryBlocks(bl, br, st);
        p = br * BS;
    }

    while (p <= r) {
        applyPlatform(st, d[p], s[p], tmp);
        memcpy(st, tmp, X * sizeof(ll));
        ++p;
    }

    return st[X - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q >> X;

    vector<int> d(n);
    vector<ll> s(n);

    for (int& v : d) cin >> v;
    for (ll& v : s) cin >> v;

    SegTree seg(d, s);

    while (q--) {
        char op;
        cin >> op;

        if (op == '1') {
            int i, v;
            cin >> i >> v;
            --i;
            d[i] = v;
            seg.update(i);
        } else if (op == '2') {
            int i;
            ll v;
            cin >> i >> v;
            --i;
            s[i] = v;
            seg.update(i);
        } else {
            int l, r;
            cin >> l >> r;
            cout << solve(--l, --r, d, s, seg) << '\n';
        }
    }
}
