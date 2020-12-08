#include <bits/stdc++.h>
using namespace std;

int main()
{

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, K;
        cin >> N >> K;
        int trackNegative = 0;
        int negativeNumber = N - K;
        vector<int> seq(N);
        for (int j = 0; j < seq.size(); j++)
        {
            if (j % 2 == 0)
            {
                if (trackNegative < negativeNumber)
                {
                    seq[j] = -(j + 1);
                    trackNegative++;
                }
                else
                {
                    seq[j] = (j + 1);
                }
            }
            else
            {
                seq[j] = (j + 1);
            }
        }
        if (trackNegative < negativeNumber)
        {
            for (auto k = seq.rbegin(); k != seq.rend(); k++)
            {

                if (*k > 0 && trackNegative < negativeNumber)
                {
                    *k = (*k) * (-1);
                    trackNegative++;
                }
            }
             for (auto x : seq)
            {
                cout << x << " ";
            }
        }
        else
        {
            for (auto x : seq)
            {
                cout << x << " ";
            }
        }
        //  for (auto x : seq)
        //     {
        //         cout << x << " ";
        //     }
    }
    return 0;
}