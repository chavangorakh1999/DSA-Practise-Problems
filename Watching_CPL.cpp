#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
          
        int n,k,cnt=0;
        cin>>n>>k;
        int box[n-1];
        int sum=0;

        for(int i=0;i<n;i++){
            cin>>box[i];
            sum+=box[i];
        }
        sort(box,box+n,greater<int>());
        if(sum < 2*k){
            cout<<-1<<"\n";
        }
        else if(sum== 2*k){
            cout<<n<<"\n";
        }
        else if(sum > 2*k){
            int i;
            int sumS=0;
            for(i=0;i<n;i++){
                sumS+=box[i];
                if(sumS>2*k)break;
            }
            cout<<i+1<<"\n";
        }
        
    }
    return 0;
}