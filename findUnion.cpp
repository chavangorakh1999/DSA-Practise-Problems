#include <bits/stdc++.h>
using namespace std;

void Union(vector<int> a, vector<int> b)
{
    vector<int> smallerArray, BiggerArray;
    if (a.size() > b.size())
    {
        smallerArray = b;
        BiggerArray = a;
    }
    else
    {
        smallerArray = a;
        BiggerArray = b;
    }
    for (int i = 0; i < smallerArray.size(); i++)
    {
        if (binary_search(BiggerArray.begin(), BiggerArray.end(), smallerArray[i]))
        {
            cout << smallerArray[i] << " ";
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    Union(a, b);

    return 0;
}