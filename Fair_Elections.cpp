#include <bits/stdc++.h>
using namespace std;
void swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N,M;
        cin>>N>>M;
        int A[N];
        int B[M];
        int sumA=0,sumB=0;
        for(int i=0;i<N;i++){
            cin>>A[i];
            sumA+=A[i];
        }
        for(int i=0;i<M;i++){
            cin>>B[i];
            sumB+=B[i];
        }
        if(sumA>sumB){
            cout<<0<<"\n";
        }
        else{
            sort(A,A+N);
            sort(B,B+M);
            reverse(B,B+M);
            int j=0,c=0;
            for(int i=0;i< N ;++i){
                if(j<M){
                    sumA=sumA-A[i]+B[j];
                    sumB=sumB-B[j]+A[i];
                    swap(A[i],B[j]);
                    c++;
                    j++;
                    if(sumA>sumB){
                        break;
                    }
                }
            }
            cout<<c<<"\n";
        }
        // int swapCount=0;
        // bool print=true;
        // while(sum(A)<=sum(B)){
        //   sort(A.begin(),A.end());
        //   sort(B.begin(),B.end());
        //   if(A[0]<B[M-1]){
        //     swap(A[0],B[M-1]);
        //     swapCount+=1;
        //   }else
        //   {
        //       print=false;
        //       cout<<-1;
        //   }
          
        // }
        
        // if(print) cout<<swapCount<<"\n";

        
        
    }
    return 0;
}

// i=0
// printer=True
// while sum(alist)<=sum(blist):
// alist.sort()
// blist.sort()
// if alist[0]<blist[-1]  :
// temp=blist[-1]
// blist[-1]=alist[0]
// alist[0]=temp
// i+=1
// else:
// printer=False
// print(-1)
// break
// if printer==True:
// print(i)