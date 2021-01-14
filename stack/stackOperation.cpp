#include<iostream>
#include"stackUsingLinkedList.cpp"
using namespace std;

int main(){
int t;
cin>>t;
Stack<char>   s;
while(t--){
s.push(100);
}
s.push(105);
cout<<s.getSize();
cout<<s.pop();
cout<<s.pop();
return 0;
}
