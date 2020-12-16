#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int>final(n);
    int k=0;
    for(int i=0,j=n-1;i<=j;i++,j--){
        final[k++]=v[i];
        final[k++]=v[j];
        
    }

    for(int i=0;i<n;i++){
        cout<<final[i]<<" ";
    }
    cout<<"\n";
    }

    return 0;
}