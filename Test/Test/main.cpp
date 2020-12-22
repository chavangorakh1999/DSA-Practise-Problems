//
//  main.cpp
//  Test
//
//  Created by Gorakh Chavan on 20/12/20.
//

#include <iostream>
using namespace std;

void mergeSort(int *a, int startIndex, int endIndex)
{
    if (startIndex >= endIndex)
    {
        return;
    }
    int mid = (startIndex + endIndex) / 2;
    mergeSort(a, startIndex, mid);
    mergeSort(a, mid + 1, endIndex);
    int b[endIndex+1];
    int k = 0;
    for (int i = startIndex, j = mid + 1; j <= endIndex; i++, j++)
    {
        if (a[i] > a[j])
        {
            b[k++] = a[j];
        }
        else
        {
            b[k++] = a[i];
        }
    }
    for(int i=0;i<=endIndex;i++){
        a[i]=b[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a,0,n-1);
    return 0;
}
