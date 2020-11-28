#include<bits/stdc++.h>

using namespace std;

// class model {
//     public:
//     int x;
//     int y;

//     model(int a,int b){
//          x=a;
//          y=b;
//     };

//     void print(){
//         cout<<x<<" "<<y;
//     }
// };


void fun(int *a)
{
    a = (int*)malloc(sizeof(int));
}
  
int main()
{
    int *p = (int*)malloc(sizeof(int));
 
    p = NULL;
 
    free(p);
}