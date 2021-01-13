#include <bits/stdc++.h>
using namespace std;
int main()
{
    string variable = "quinstreet";
    int n = 2;
   
    for(int i=0;i < variable.size()-1;i++)
    {
        int count=0;
        
        for(int j=i+1; j < variable.size();j++)
        { 
           if(variable[i] == variable[j]){
               count++;
           }

            
        }
        if(count==(n-1)){
            cout<<variable[i]<<"->"<<n<<endl;
        }
    }
    return 0;
    // int d=1;
    // for(int i=0;i<5;i++){
        
    //     for(int j=0;j< d;j++){
    //         cout<<"*";
    //     }
    //     for(int k=0;k<i+1;k++){
    //         cout<<0;
    //     }
    //     cout<<endl;
    //     d=d+(i+2);

    // }

}
