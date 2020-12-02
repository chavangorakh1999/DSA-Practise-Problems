#include<bits/stdc++.h>
using namespace std;


void segrigate(vector<int> &v,int T){
    int count0=0,count1=0;
    for(int i=0;i<T;i++){
        if(v[i]==0){
            count0++;
        } 
        else if(v[i]==1){
            count1++;
        }
    }
    for(int i=0;i<count0;i++){
        v[i]=0;
    }
    int start_pt=count0+count1;
    for(int i=count0;i<start_pt;i++){
        v[i]=1;
    }
    for(int i=start_pt;i<T;i++){
        v[i]=2;
    }
}

void print(vector<int> v,int T){
     for(int i=0;i<T;i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    int T; 
    cin>>T;
    vector<int> v(T,0);
    for(int i=0;i<T;i++){
        cin>>v[i];
       
    }
    segrigate(v,T);
    print(v,T);
   
   return 0;
}