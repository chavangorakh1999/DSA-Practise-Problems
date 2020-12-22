#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define ll long long
#define int long long
#define endl '\n'

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        s=" "+s;
        int mask[n+1];
        mask[0]=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='?')
                mask[i]=mask[i-1];
            else
                mask[i]=mask[i-1]^(1<<(int)(s[i]-'a'));
        }
        int mask_with[n+1];
        mask_with[0]=0;
        map<int,int> mp;
        mp[0]++;
        int ques=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='?')
                ques++;
            int curr=((1<<26)*(ques%2!=0))|(mask[i]);
            mp[curr]++;
            mask_with[i]=curr;
        }
        int ans=0;
        ques=0;
        for(int i=0;i<=n;i++)
        {
            if(s[i]=='?')
                ques++;
            mp[mask_with[i]]--;
            int req=((1<<26)*((ques%2)!=0))|(mask[n]^mask[i]);
            ans+=mp[req];
            req=((1<<26)^req);
            for(int j=0;j<26;j++)
            {
                int tmp=req;
                tmp=((1<<j)^tmp);
                ans+=mp[tmp];
            }
        }
        cout<<ans<<endl;
    }   
}