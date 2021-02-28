#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    unordered_map<string,int> ourmap;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int val;
        string Key;
        cin>>Key>>val;
        ourmap[Key]=val;
    }

    unordered_map<string,int>::iterator it=ourmap.begin();
    while(it!=ourmap.end()){
        cout<<"Key :"<<it->first<<" Value :"<<it->second<<endl;
        it++;
    }
    cout<<"------------------"<<endl;

    unordered_map<string,int>::iterator it1=ourmap.find("abc3");
    ourmap.erase(it1);
    it=ourmap.begin();
     while(it!=ourmap.end()){
        cout<<"Key :"<<it->first<<" Value :"<<it->second<<endl;
        it++;
    }

    return 0;
}
