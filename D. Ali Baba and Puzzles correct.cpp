#include <iostream>
using namespace std;

int main() 
{
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    long long ab = a*b;
    long long bc = b*c;

    bool ok =(a+b-c == d)||(a+bc == d)||(a-b + c == d)||(a-bc ==d)||(ab + c == d)||(ab - c == d);
    cout <<(ok ?"YES":"NO") << endl;
    return 0;
}