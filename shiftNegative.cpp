#include <bits/stdc++.h>
using namespace std;
void rearrange(int *arr,int n){
    int front,back;
    front=0;
    back=n-1;

    while(front<=back){
        if(arr[front]<0&& arr[back]<0){
            front++;
        }
       else if(arr[front]>0 && arr[back]<0){
           int temp=arr[back];
           arr[back]=arr[front];
           arr[front]=temp;
        } else if(arr[front]<0 && arr[back]>0){
            back--;
        }else{
            front++;
            back--;
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rearrange(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}