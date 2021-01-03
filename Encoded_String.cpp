#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string encodedString;
        cin >> encodedString;
        string c;
        c = "abcdefghijklmnop";

        int count = n / 4;
        int i = 0;
        int k = 4;
        while (count)
        {
            int start = 0;
            int end = 16;
            int mid = 8;
            for (; i < k; i++)
            {
                if (encodedString[i] == '1')
                {
                    start = mid;
                    mid = start + (end - start) / 2;
                }
                else
                {
                    end = mid;
                    mid = start + (end - start) / 2;
                }
            }
            cout << c[start];
            count--;

            k += 4;
        }
        cout << "\n";
    }
    return 0;
}