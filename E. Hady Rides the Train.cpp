#include <iostream>
using namespace std;

int main() 
{
    long long id;
    cin >> id;
    long long row = id/4;
    long long column;

    if(row % 2 == 0){
        column = id % 4;
    }
    else {
        column = 3 - (id % 4);
    }
    cout << row << " " << column << endl;
    return 0;
}