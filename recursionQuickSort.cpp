#include<iostream>
using namespace std;
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition(int *a,int startIndex,int lastIndex){
    int pivot=a[lastIndex];
    int i=(startIndex-1);

    for (int j=startIndex;j<=lastIndex-1;j++){
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[lastIndex]);
    return i+1;
}

void quickSort(int *a,int startIndex,int lastIndex){
    if(startIndex >= lastIndex){
        return;
    }
    int c= partition(a,startIndex,lastIndex);
    quickSort(a,startIndex,c-1);
    quickSort(a,c+1,lastIndex);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}