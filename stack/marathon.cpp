#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<float> distances;
    float first, second, third;
    float max=42.195 ;
    first = second = third = INT_MIN;
    float input;
    while ((cin >> input) && input != 'q')
        distances.push_back(input);

    for (int i = 0; i < distances.size(); i++)
    {   if(distances[i]<max){
        if ( distances[i] > first)
        {
            third = second;
            second = first;
            first = distances[i];
        }else if(distances[i]>second){
            third=second;
            second=distances[i];
        }else if(distances[i] >third ){
            third=distances[i];
        }
        }
    }

    if(first>0) cout<<first<<" ";
    if(second>0) cout<<second<<" ";
    if(third>0) cout<<third;
    return 0;
}