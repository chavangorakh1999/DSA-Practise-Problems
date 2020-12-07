#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
  
    cin>>T;
   
    

    for (int i = 0; i < T; i++)
    {
         double riskCount=0,noRiskCount=0;
        long double N, D;
        cin>>N>>D;
        vector<int> arr(N);
        for (int j = 0; j < N; j++)
        {
            cin >> arr[j];
        }

        for(int i=0;i<arr.size();i++){
            if(arr[i]<=9 || arr[i]>=80){
                riskCount++;
            }else{
                noRiskCount++;
            }
        }
        int riskDayCount=ceil(riskCount/D);
        int noRiskDayCount=ceil(noRiskCount/D);

        cout<<riskDayCount+noRiskDayCount<<endl;
        arr.clear();
    }
    return 0;
}