#include<iostream>
#include"stackUsingArray.cpp"
using namespace std;

int main(){
int t;
cin>>t;
StackUsingArray s;
while(t--){
s.push(10);
}
cout<<s.size();
return 0;
}