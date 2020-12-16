#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
         int X;
    cin >> X;
 
    if (X > 45) {
        cout << -1 << '\n';
        return 0;
    }
 
    int current = 9;
    string str;
 
    while (X > current) {
        str = char('0' + current) + str;
        X -= current;
        current--;
    }
 
    if (X > 0) {
        str = char('0' + X) + str;
    }
 
    cout << str << '\n';
    }

    return 0;
}