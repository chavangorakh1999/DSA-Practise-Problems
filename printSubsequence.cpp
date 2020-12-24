#include <bits/stdc++.h>
using namespace std;

void printSubSequence(string input,string output){

    if(input.empty()){
        cout<<output<<"\n";
        return;
    }
    printSubSequence(input.substr(1),output);
    printSubSequence(input.substr(1), output + input[0]);
}

int main()
{
    string input,output="";
    cin>>input;
    printSubSequence(input,output);
    return 0;
}