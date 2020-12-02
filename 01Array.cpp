#include<bits/stdc++.h>
using namespace std;


void segrigate(vector<int> v,int T){
    int count=0;
    for(int i=0;i<T;i++){
        if(v[i]==0){
            count++;
        } 
    }
    for(int i=0;i<count;i++){
        v[i]=0;
    }
    for(int i=count;i<T;i++){
        v[i]=1;
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