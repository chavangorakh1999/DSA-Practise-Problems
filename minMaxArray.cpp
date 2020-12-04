#include <bits/stdc++.h>
using namespace std;

struct minMax
{
    int min;
    int max;
};

//Iterative Method

minMax findMinMax(int *arr, int n)
{
    int temp;
    minMax m;
    m.min = INT_MAX;
    m.max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (m.min > arr[i])
        {
            m.min = arr[i];
        }
        else if (m.max < arr[i])
        {
            m.max = arr[i];
        }
    }
    return m;
}

//Tournament Method

minMax TournamentMinMax(int *arr, int low, int high)
{
    minMax m, mmR, mmL;
    int mid;
    if (low == high)
    {
        m.max = m.min = arr[low];
        return m;
    }
    else if (low + 1 == high)
    {
        if (arr[low] > arr[high])
        {
            m.min = arr[high];
            m.max = arr[low];
        }
        else
        {
            m.min = arr[low];
            m.max = arr[high];
        }
        return m;
    }
    mid = (low + high) / 2;
    mmL = TournamentMinMax(arr, low, mid);
    mmR = TournamentMinMax(arr, mid + 1, high);

    if (mmL.min > mmR.min)
    {
        m.min = mmR.min;
    }
    else
    {
        m.min = mmL.min;
    }

    if (mmR.max > mmL.max)
    {
        m.max = mmR.max;
    }
    else
    {
        m.max = mmL.max;
    }

    return m;
}
 
//Pair comparison method

minMax PairminMax(int * arr,int n){
    int i=0;
    minMax m;
    if(n%2==0){
        if(arr[0]>arr[1]){
            m.max=arr[0];
            m.min=arr[1];
        }else
        {
            m.max=arr[1];
            m.min=arr[0];
        }
     i=2;   
    }else
    {
        m.min=arr[0];
        m.max=arr[0];
        i=1;
    }

    while(i< n-1){
        if(arr[i]>arr[i+1]){
            if(arr[i]>m.max){
                m.max=arr[i];
            }

            if(arr[i+1]<m.min){
                m.min=arr[i+1];
            }
        }else
        {
            if(arr[i+1]>m.max){
                m.max=arr[i+1];
            }
            if(arr[i]<m.min){
                m.min=arr[i];
            }
        }
        i+=2;
    }
    return m;
}

int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // minMax res = TournamentMinMax(arr, 0, n - 1);
    minMax res=PairminMax(arr,n);
    cout << "MIN:" << res.min << " "
         << "MAX:" << res.max;
    return 0;
}