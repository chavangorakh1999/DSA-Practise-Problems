#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string, int > ourmap;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        string Key;
        cin>>Key>>val;
        ourmap[Key]=val;
    }
    map<string,int>::iterator it=ourmap.begin();
    while(it!=ourmap.end())
    {
        cout<<"Key :"<<it->first<<" Value :"<<it->second<<endl;
        it++;
    }
return 0;
}