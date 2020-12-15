#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){

        int N,X;
        cin>>N>>X;
        vector<int> a(N);
        vector<vector<int> > bit_locs(31);
        vector<int> ptr(31,0);

         for(int i=0;i<N;i++){
            cin>>a[i];
        }
        for(int i=0;i<N;i++){
            for (int j=30;j>=0;j--){
                if((1 << j) & a[i])
                    bit_locs[j].push_back(i);
            }
        }
        int operations=0;
        for(int i=0;i<N-1;i++){
            if(operations == X)
                break;
            for(int j=30;j>=0;j--){
                if (operations == X)
					break;
                    
                if((1<<j)& a[i]){
                    if(ptr[j]+1 < (int)bit_locs[j].size()){
                        a[i] ^= (1<<j);
                        a[ bit_locs[j] [ptr [j] + 1 ] ] ^= (1 << j);
                        ptr[j] +=2;
                    }else
                    {
                        a[i] ^=(1<<j);
                        a[N-1] ^=(1<<j);
                    }
                    operations++;
                }
            }
            
        }
    int Y=X-operations;

    if(N==2 && Y % 2 == 1){
        a[N-1] ^= 1;
        a[N-2] ^= 1;
    }
    for(int i=0;i<N;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    }

    return 0;
}