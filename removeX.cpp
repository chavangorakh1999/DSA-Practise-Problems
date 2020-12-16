#include<iostream>
using namespace std;

void removeX(char s[]){
    if(s[0]=='\0'){
        return;
    }
    if(s[0] != 'x'){
        removeX(s+1);
    }else
    {
        int i=1;
        for(;s[i] != '\0';i++){
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        removeX(s);
    }
    
}

int length(char *s){
    if(s[0]=='\0'){
        return 0;
    }
    int smallLength=length(s+1);
    return 1 + smallLength;
}

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        char s[100];
        cin>>s;
        int n = length(s);
        cout<<n<<"\n";
        removeX(s);
        cout<<s;
    }
}