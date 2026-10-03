#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        string s,v,c; cin>>s;
        for(char ch:s) (strchr("aeiou",ch)?v:c)+=ch;
        auto pal=[](string x){return equal(x.begin(),x.end(),x.rbegin());};
        bool ok=pal(v)&&pal(c);
        if(s.size()%2==0&&v.size()%2) ok=false;
        puts(ok?"YES":"NO");
    }
}
