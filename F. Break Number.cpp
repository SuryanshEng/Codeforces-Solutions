#include <iostream>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    int ans = 0;
    while(N--){
        long long x;
        cin >> x;
        int count = 0;
        while(x % 2 == 0){
            x /= 2;
            count++;
        }
        ans = max(ans,count);
    }
    cout << ans << endl;
    return 0;
}