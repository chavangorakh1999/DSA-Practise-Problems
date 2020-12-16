#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        string S;
        cin>>N>>S;
     bool possible = false;
 
    for (int first = 0; first <= 4; first++) {
        int second = 4 - first;
 
        if (S.substr(0, first) + S.substr(N - second) == "2020")
            possible = true;
    }
 
    cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}