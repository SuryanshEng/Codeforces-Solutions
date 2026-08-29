#include <iostream>
using namespace std;

int main() 
{
    long long n,m,k,answer;
    cin >> n >> m >> k;
    answer = min(k, min(n,m) + (n-min(n,m))/2);
    cout << answer;
    return 0;
}