#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> f(n + 1);
    vector<int> head(n + 1, 0), nxt(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
        nxt[i] = head[f[i]];
        head[f[i]] = i;
    }

    vector<int> q;
    q.reserve(n);
    vector<bool> vis(n + 1, false);

    q.push_back(1);
    vis[1] = true;
    int head_ptr = 0;
    
    while (head_ptr < (int)q.size()) {
        int u = q[head_ptr++];
        for (int v = head[u]; v; v = nxt[v]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push_back(v);
            }
        }
    }
    
    int ans = q.size();
    vector<int> c;
    
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            int start_idx = q.size();
            q.push_back(i);
            vis[i] = true;
            
            while (head_ptr < (int)q.size()) {
                int u = q[head_ptr++];
                
                if (!vis[f[u]]) {
                    vis[f[u]] = true;
                    q.push_back(f[u]);
                }
                
                for (int v = head[u]; v; v = nxt[v]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push_back(v);
                    }
                }
            }
            c.push_back(q.size() - start_idx); 
        }
    }
    
    sort(c.rbegin(), c.rend());
    for (int i = 0; i < min(k, (int)c.size()); ++i) {
        ans += c[i];
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}
