#include<iostream>
using namespace std;

int indexOccurance(int *arr,int size,int x,int *output){
    if(size==0){
        return 0;
    }
    int smallAns=indexOccurance(arr,size-1,x,output);
    if(arr[size-1]==x){
        output[smallAns]=size-1;
        smallAns++;
    }
    return smallAns;
}

void printAllIndexes(int *arr,int size,int x){

    int output[size];
    int ans=indexOccurance(arr,size,x,output);
    if(ans==0){
        cout<<"element does not exist"<<"\n";
    }
    for(int i=0;i<ans;i++){
        cout<<output[i]<<" ";
    }
}


int main(){

    int size,x;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cin>>x;

    printAllIndexes(arr,size,x);
    return 0;
}