#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=998244353;
ll pw(ll b,ll e=M-2){ll r=1;for(b%=M;e;e>>=1,b=b*b%M)if(e&1)r=r*b%M;return r;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n,K; cin>>n>>K;
        vector<ll> l(n),r(n);
        vector<pair<ll,int>> ev;
        for(int i=0;i<n;i++){
            cin>>l[i]>>r[i];
            ev.push_back({l[i],i+1});
            ev.push_back({r[i]+1,-(i+1)});
        }
        sort(ev.begin(),ev.end());
        vector<ll> P(K+1,0);
        P[0]=1;
        int z=0;
        ll ans=0, prev=ev[0].first;
        for(auto&[pos,id]:ev){
            ll coef=z<=K?P[K-z]:0;
            ans=(ans+(pos-prev)%M*coef)%M;
            prev=pos;
            int i=abs(id)-1;
            ll len=r[i]-l[i]+1;
            if(id>0){
                if(len==1) z++;
                else{
                    ll p=pw(len),q=(len-1)*p%M;
                    for(int j=K;j>=0;j--) P[j]=(P[j]*q+(j?P[j-1]*p:0))%M;
                }
            }else{
                if(len==1) z--;
                else{
                    ll p=pw(len),iq=len*pw(len-1)%M;
                    for(int j=0;j<=K;j++) P[j]=((P[j]-(j?p*P[j-1]%M:0))%M+M)%M*iq%M;
                }
            }
        }
        cout<<ans<<"\n";
    }
}
