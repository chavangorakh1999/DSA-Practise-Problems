#include<bits/stdc++.h>
using namespace std;

//Itterative Way to reverse an array

void reverse(int *arr,int T){
    // int temp[T];
    int temp=0;
    for(int i=0,j=T-1;i<j;i++,j--){
        temp= arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        
    }
    for(int i=0;i<T;i++){
        cout<<arr[i]<<" ";
    }
}

void recReverse(int *arr,int start,int end){
    if(start >= end)
        return;
    
    int temp= arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        recReverse(arr, start+1, end-1);
}
void print(int *arr,int T){

     for(int i=0;i<T;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int T;
    cin>>T;
    int arr[T];
    for(int i=0;i<T;i++){
        cin>>arr[i];
    }
    recReverse(arr,0,T-1);
    print(arr,T);
    return 0;
}