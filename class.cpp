#include<bits/stdc++.h>

using namespace std;

class model {
    public:
    int x;
    int y;

    model(int a,int b){
         x=a;
         y=b;
    };

    void print(){
        cout<<x<<" "<<y;
    }
};

int main(){
    int x,y;
    cin>>x>>y;
    
    model m(x,y);
    m.print();
    return 0;
}