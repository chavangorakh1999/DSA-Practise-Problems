#include<iostream>
#include"stackUsingArray.cpp"
using namespace std;

int main(){
    StackUsingArray s;
    s.push(5);
    s.pop();
     s.push(5);
    cout<<s.size();
    return 0;
}