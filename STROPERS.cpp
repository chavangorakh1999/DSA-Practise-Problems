#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size(),i,j;
    set<tuple<int, int, int>> eq;
    for(i=0;i<n;i++){
        int even=0,odd=0,cnt=0;
        for(j=i;j<n;j++){
            if(s[j] == '1'){
                cnt++;
            }else{
                if(cnt % 2){
                    odd++;
                }else{
                    even++;
                }
            }
            int len=j-i+1;
            eq.insert({len,even,odd});
        }
    }
    cout<<eq.size()<<"\n";
    }
    return 0;
}