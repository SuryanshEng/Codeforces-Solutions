// Antigun and Lamus (Easy Version) — corrected solution

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
const int MX=3005;
int spf[MX];

int main(){
    for(int i=2;i<MX;i++) if(!spf[i]) for(int j=i;j<MX;j+=i) if(!spf[j]) spf[j]=i;

    int T; scanf("%d",&T);
    while(T--){
        int n; scanf("%d",&n);
        vector<int> a(n);
        for(auto&x:a) scanf("%d",&x);
        sort(a.begin(),a.end());

        vector<ll> pw(n+1); pw[0]=1;
        for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%MOD;

        // prime factor lists for 1..n
        vector<vector<int>> primesOf(n+1);
        for(int m=2;m<=n;m++){
            int x=m;
            while(x>1){int p=spf[x]; primesOf[m].push_back(p); while(x%p==0)x/=p;}
        }

        // smooth[m] = sorted list of numbers w in (m,n] with prime-factor-set(w) subset prime-factor-set(m)
        vector<vector<int>> smooth(n+1);
        vector<char> inP(n+1,0);
        for(int m=1;m<=n;m++){
            for(int p:primesOf[m]) inP[p]=1;
            for(int w=m+1; w<=n; w++){
                int y=w; bool ok=true;
                while(y>1){int p=spf[y]; if(!inP[p]){ok=false;break;} while(y%p==0)y/=p;}
                if(ok) smooth[m].push_back(w);
            }
            for(int p:primesOf[m]) inP[p]=0;
        }

        // DP table ans[m][M] for M in [m,n], stored as vector of vectors sized (n+1-m) offset, but simplest: full (n+1)x(n+1) int array
        vector<vector<int>> ans(n+1, vector<int>(n+1,0));
        for(int m=1;m<=n;m++){
            ans[m][m]=m;
            auto &lst = smooth[m];
            for(int M=m+1;M<=n;M++){
                // largest element in lst <= M
                int idx = (int)(upper_bound(lst.begin(), lst.end(), M) - lst.begin()) - 1;
                if(idx<0) ans[m][M]=m;
                else{
                    int W=lst[idx];
                    ans[m][M] = (m==1? 1 : ans[m-1][W-1]);
                }
            }
        }

        ll total=0;
        // singles
        for(int i=0;i<n;i++) total=(total + a[i])%MOD;
        // pairs
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int m=a[i-1], M=a[j-1];
                ll val = ans[m][M];
                total = (total + val%MOD * pw[j-i-1]) % MOD;
            }
        }
        printf("%lld\n", total);
    }
}
