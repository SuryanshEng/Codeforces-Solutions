#include <bits/stdc++.h>
using namespace std;
const long long M=998244353;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<int> a(n+1), mx, mn;
        vector<long long> b(n+1,0), val(n+1,0), dp(n+1,0);
        dp[0]=1;
        auto upd=[&](int i,long long v){ for(;i<=n;i+=i&-i) b[i]=((b[i]+v)%M+M)%M; };
        auto qry=[&](int i){ long long s=0; for(;i;i-=i&-i) s+=b[i]; return s%M; };
        for(int r=1;r<=n;r++){
            scanf("%d",&a[r]);
            // l stays valid as "max" only if nothing bigger appears after it
            while(!mx.empty() && a[mx.back()]<a[r]){ upd(mx.back(),-val[mx.back()]); mx.pop_back(); }
            mx.push_back(r);
            val[r]=dp[r-1]; upd(r,val[r]);
            // a[r] must be min: l must be after the previous smaller element
            while(!mn.empty() && a[mn.back()]>a[r]) mn.pop_back();
            int ps=mn.empty()?0:mn.back();
            mn.push_back(r);
            dp[r]=((qry(r)-qry(ps))%M+M)%M;
        }
        printf("%lld\n",dp[n]);
    }
}
