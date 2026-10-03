#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n; scanf("%d",&n);
        vector<long long> a(n);
        long long s=0;
        for(auto&x:a) scanf("%lld",&x), s+=x;
        bool ok;
        if(s>n) ok=false;          // too many chips: never stops
        else if(s<n) ok=true;      // too few chips: always stops
        else{                      // s==n: stops iff it can reach all ones
            long long p=0,sum=0;
            for(int i=0;i<n;i++){ p+=a[i]-1; sum+=p; }
            ok=(sum%n==0);
        }
        puts(ok?"YES":"NO");
    }
}
