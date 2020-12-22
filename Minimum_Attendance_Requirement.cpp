#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int count=0;
       for(int i=0;i<n;i++){
            if(a[i]=='1') 
            {
                count++;
            }
        }
       
        int mostPresentDays=(120-(n-count));
    float percent=((mostPresentDays*100)/120);
        
        if(percent >= 75){
            cout<<"YES"<<"\n";
        }else
        {
            cout<<"NO"<<"\n";
        }
        
    }
}