#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a!=0 && b!=0 && c!= 0){
            int sum=a+b+c;
            sum= sum-2;
        if(sum%7==0){
            cout<<"YES"<<"\n";
        }else
        {
            cout<<"NO"<<"\n";
        }
        }else{
                 int sum=a+b+c;
            sum= sum-3;
        if(sum%7==0){
            cout<<"YES"<<"\n";
        }else
        {
            cout<<"NO"<<"\n";
        }
        }
        
        

        
    }
    return 0;
}