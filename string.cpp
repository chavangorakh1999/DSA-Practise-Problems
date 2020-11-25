
#include<bits/stdc++.h>

using namespace std;

char *encode(char *src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		char str[10000];
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}


/*You are required to complete this function */

char *encode(char *src)
{     
  int rLen;
  char count[100001];
  int len = strlen(src);
 
  char *dest =new char[len];
  
  int i, j = 0, k;
 
 
  for(i = 0; i < len; i++)
  {
 
    
    dest[j++] = src[i];
     
    
    rLen = 1;     
    while(i + 1 < len && src[i] == src[i+1])
    {
      rLen++;
      i++;
    }   
     
    
    sprintf(count, "%d", rLen);


    for(k = 0; *(count+k); k++, j++)
    { 
      dest[j] = count[k]; 
    } 
  }  
 

  dest[j] = '\0';
  return dest;
}     
 

































