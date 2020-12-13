#include<iostream>
using namespace std;

int fib(int number){
    if(number==0){
        return 0;
    }
    if(number==1){
        return 1;
    }
    return fib(number-1)+fib(number- 2);

}

bool checkSorted(int *arr,int size){
    if(size==1 || size == 0){
        return true;
    }
    // if(arr[0]>arr[1]){
    //     return false;
    // }
 bool smallAns=checkSorted(arr+1,size-1);
 


if(!smallAns){
    return false;
}
if(arr[0]>arr[1]){
    return false;
} 
else
{
    return true;
}
}

int firstIndex(int *arr,int size,int x){
    if(size==0){
        return -1;
    }
    if(arr[0]==x){
        return 0;
    }
    int ans=firstIndex(arr+1,size-1,x);
    if(ans == -1){
        return -1;
    }else
    {
        return ans+1;
    }
    

}

int lastIndex(int *arr,int size,int x){
    if(size==0){
        return -1;
    }
    int ans = lastIndex(arr+1,size-1,x);
    
    if(ans==-1){
        if(arr[0]==x){
            return 0;
        }else
        {
            return -1;
        }
        
    }else
    {
        return ans+1;
    }
   
    

}


int main(){
    // int arr[5]={1,4,6,7,3};
    int arr[5]={1,2,5,4,5};
    // int n=fib(4);

    // cout<<checkSorted(arr,5)<<"\n";
    cout<<lastIndex(arr,5,9);
    return 0;
}