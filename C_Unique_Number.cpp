#include<iostream>
using namespace std;
void run_case() {
    int X;
    cin >> X;
 
    if (X > 45) {
        cout << -1 << '\n';
        return;
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
 
int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

 
    int tests;
    cin >> tests;
 
    while (tests-- > 0)
        run_case();
}