#include<iostream>
#include<cmath>
using namespace std;

int seq(string s,string *output){
    if(s.empty()){
        output[0]="";
        return 1;
    }
    string smallInputString=s.substr(1);
    int smallOutputSize=seq(smallInputString,output);
    for(int i=0;i<smallOutputSize;i++){
        output[i+smallOutputSize]=s[0]+output[i];
    }
    return 2*smallOutputSize;
}
int main(){
    string s;
    getline(cin,s);
    int outputSize=pow(2,s.size());
    string *output=new string[outputSize];
    int outputArraySize = seq(s,output);
     for(int i=0;i<outputArraySize;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}