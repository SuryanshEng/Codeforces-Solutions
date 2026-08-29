#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,A,B;
    cin >> N >> A >> B;
    int answer = 0;
    for(int i = 1; i <= N;i++){
        int temp,digitSum;
        temp = i;
        digitSum = 0;
        while(temp > 0) {
            digitSum += temp % 10;
            temp /= 10;
        }
            if(A <= digitSum && digitSum <= B){
                answer +=i;
            }
    }
    cout << answer;
    return 0;
}