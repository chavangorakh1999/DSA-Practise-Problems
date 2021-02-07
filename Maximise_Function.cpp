#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {   long long n;
        cin>>n;
        vector<long long> v;
        for(long long i=0;i<n;i++){
            long long x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        long temp=v[0];
        // for(auto x: v){
        // if(x!=temp){
        //     cout<<"0"<<endl;
        //     break;
        // }
        // }
         cout<<abs(v[0]-v[n-1])+ abs(v[n-1]-v[1])+ abs(v[1]-v[0])<<endl;
        }
    return 0;
}