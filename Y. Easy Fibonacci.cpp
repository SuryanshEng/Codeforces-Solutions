#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long a = 0,b = 1;
    for(int i = 0; i < N;i++){
        cout << a << " ";
    long long next = a+b;
    a = b;
    b = next;    
    }
    return 0;
}