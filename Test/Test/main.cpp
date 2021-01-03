////
////  main.cpp
////  Test
////
////  Created by Gorakh Chavan on 20/12/20.
////
//
//#include <iostream>
//using namespace std;
//
//void mergeSort(int *a, int startIndex, int endIndex)
//{
//    if (startIndex >= endIndex)
//    {
//        return;
//    }
//    int mid = (startIndex + endIndex) / 2;
//    mergeSort(a, startIndex, mid);
//    mergeSort(a, mid + 1, endIndex);
//    int b[endIndex+1];
//    int k = 0;
//    for (int i = startIndex, j = mid + 1; j <= endIndex; i++, j++)
//    {
//        if (a[i] > a[j])
//        {
//            b[k++] = a[j];
//        }
//        else
//        {
//            b[k++] = a[i];
//        }
//    }
//    for(int i=0;i<=endIndex;i++){
//        a[i]=b[i];
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    int a[n];
//    for (int i = 0; i < n; i++)
//    {
//        cin >> a[i];
//    }
//    mergeSort(a,0,n-1);
//    return 0;
//}


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string encodedString;
        cin>>encodedString;
        string c;
        c="abcdefghijklmnop";
        
        int count=n/4;
        int i=0;
        int k=4;
        while(count){
            int start=0;
            int end=16;
            int mid=8;
            for(;i<k;i++){
            if(encodedString[i]=='1'){
              start=mid;
              mid=start+(end-start)/2;
            }else
            {
                end=mid;
                mid=start+(end-start)/2;
            }
            
        }
        cout<<c[start];
        count--;
        
        k+=4;
        }
        cout<<"\n";
        
    }
    return 0;
}
