#include<bits/stdc++.h> 
using namespace std; 

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int,int>;
using pl = pair<ll, ll>;
using vii = vector<pi>;
using vll = vector<pl>;

void solve()
{

}

ll gcd(ll a, ll b) 
{ 
    if (a == 0) return b; 
    return gcd(b % a, a); 
} 
ll gcdAll(vl v, ll n) 
{ 
    ll res = v[0]; 
    for (ll i = 1; i < n; i++) 
    { 
        res = gcd(v[i], res); 
  
        if(res == 1) 
        { 
           return 1; 
        } 
    } 
    return res; 
} 
ll factorise(ll z){
    ll v = 1;

    for(ll i=1;i*i<=z;i++){
        if(z%i==0) {
            v = i;
            z /= i;
        }
    }
    return v;
}
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t = 1;
    cin >> t;
    
    while(t--)
    {
        ll n,m;
        cin >> n>>m; 
        
        ll p[m];
        vl v,vf;
        for(ll i=0;i<m;i++)
        {
             cin >> p[i];
             v.push_back(p[i]);
        }
        ll size = v.size();
        ll ans;
        if(size==1) ans = v[0];
        else {
            ans = gcdAll(v,size);
        }
            if (ans == n) ans = 0;
            else if(ans<n) ans = n-ans;
            else{
          ll f=1;
          ll z=1;
          while(z*z<=ans && z<=n){
             if(ans%z==0){
                 ll o=ans/z;
                 if(o<=n){
                     f=max(o,f);
                 }
                 else if(z<=n){
                     f=max(z,f);
                 }
             }
             z++;
          }
          ans=n-f;
      }
           

        
        cout << ans<<'\n';
        
    }
	
    return 0;
}
