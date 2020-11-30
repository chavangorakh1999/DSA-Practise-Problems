#include <bits/stdc++.h>

using namespace std;

int main(){

    // T is number of test cases size is actual size of array.
    int T,n;
    cin>>n>>T;

    //p is starting index q is ending index and num is entity by which index is to be incremented.
    int p=0,q=0,num=0;
    vector<long int> v(n+1,0);
    // Taking input for T times and incrementing p index and decrementing q+1 index buy num. 
    for(int i=0; i< T;i++){
        cin>>p>>q>>num;
        v[p] += num;
        if(q+1<=n){
            v[q+1]-=num;
        }
    }
    // calculating the prefix sum.
    for(int i= 1;i<v.size();i++){
        v[i]+=v[i-1];
    }
   
     for(int i= 1;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

   //Printing the max element 
    cout<<"MAX:"<<*max_element(v.begin(), v.end())<<endl;
   
    return 0;
}


// Fastest solution you can think of.
// time complexity is O(2n) i.e O(n) and space complexity is O(n).