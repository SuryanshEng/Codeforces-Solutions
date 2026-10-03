#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T; scanf("%d",&T);
    const ll INF=LLONG_MAX/4;
    while(T--){
        int n; scanf("%d",&n);
        vector<ll> a(n);
        for(auto&v:a) scanf("%lld",&v);
        ll x=a[n-1], g=0;
        vector<pair<ll,ll>> s; // (dn, up)
        for(int i=n-2;i>=0;i--){
            g=__gcd(g,llabs(a[i+1]));
            ll up,dn;
            if(g){
                ll d=((a[i]-x)%g+g)%g;
                up=d; dn=(g-d)%g;
            } else {
                ll t=a[i]-x;
                if(t>=0) up=t,dn=INF; else dn=-t,up=INF;
            }
            s.push_back({dn,up});
        }
        sort(s.rbegin(),s.rend());
        ll ans=INF,q=0;
        int m=s.size();
        for(int k=0;k<=m;k++){
            ll p=k<m?s[k].first:0;
            if(q>=INF) break;
            if(p<INF) ans=min(ans,p+q);
            if(k<m) q=max(q,s[k].second);
        }
        printf("%lld\n",ans);
    }
}
