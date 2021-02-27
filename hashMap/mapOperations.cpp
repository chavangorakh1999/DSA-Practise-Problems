#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
unordered_map<string,int> temp;
temp["abc"]=5;
temp["xyz"]=89;
pair<string,int> p("ab",1);
temp.insert(p);

cout<<temp.at("abc")<<" ";
cout<<temp["ab"]<<" ";
cout<<temp["xyz"];
return 0;
}
