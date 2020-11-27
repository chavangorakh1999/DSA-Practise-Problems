#include<bits/stdc++.h>

using namespace std;

int remainder(int a,int b){
    int c;
    return c= a%b;
};

int main() {

    int T;
    int A,B;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>A>>B;
        cout<<remainder(A,B)<<endl;
    }
    return 0;
}