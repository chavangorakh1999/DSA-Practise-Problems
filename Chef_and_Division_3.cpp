#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int no_of_setter;
        int problems_required;
        int days;
        cin>>no_of_setter>>problems_required>>days;
        vector<int> v(no_of_setter);
        for(int i=0;i<no_of_setter;i++){
            cin>>v[i];
        }
        int sum=0;
        for(int i=0;i<no_of_setter;i++){
            sum +=v[i];
        }
        int contestCanBeConducted=(sum/problems_required);
        if(days >= contestCanBeConducted){
            cout<<contestCanBeConducted<<"\n";
        }
        else
        {
            cout<<days<<"\n";
        }
        
    }
    return 0;
}