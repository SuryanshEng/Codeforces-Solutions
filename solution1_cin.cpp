#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        long long s=0;
        for(auto&x:a) cin>>x, s+=x;
        bool ok;
        if(s>n) ok=false;
        else if(s<n) ok=true;
        else{
            long long p=0,sum=0;
            for(int i=0;i<n;i++){ p+=a[i]-1; sum+=p; }
            ok=(sum%n==0);
        }
        cout<<(ok?"YES":"NO")<<"\n";
    }
}
