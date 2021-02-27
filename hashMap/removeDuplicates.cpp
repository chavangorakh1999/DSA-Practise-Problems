#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicate(int* arr,int n){
    vector<int> result;
    unordered_map<int,bool> seen;
    for(int i=0;i<n;i++){
        if(seen.count(arr[i])>0){
            continue;
        }
        seen[arr[i]]=true;
        result.push_back(arr[i]);
    }
    return result;
}

int main(){

    int n;
    cin>>n;
    int arr[n];
     for(int i=0;i<n;i++){
         cin>>arr[i];
     }
     vector<int>result=removeDuplicate(arr,n);
     for(auto x: result){
         cout<<x<<" ";
     }
    return 0;
}