#include<iostream>
using namespace std;

void removeDuplicate(char* s){
    if(s[0]=="\0"){
        return;
    }
  if(s[0] == s[1]){
      int i=0;
      while(s[i] != '\0'){
          a[i]=a[i+1];
          i++;
      }
      removeDuplicate(s)
  }

  removeDuplicate(s+1);
}

int main(){
    int n;
    char s[n];
    cin>>s;

}