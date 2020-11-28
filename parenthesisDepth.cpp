#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> v(n+1);
	for(int i=1;i<=n;i++){
	    cin>>v[i];
	}
	int count=0,max=0,first_pos,length=0,max1=0,pos1;
	for(int i=0;i<=n;i++){
	    if(v[i]==1&&count>=0){
	        count++;
	        if(count>max){
	            max=count;
	            first_pos=i;
	        }
	    }else if(v[i]==2&&count>=0){
	        count--;
	    }
	    if(count>0){
	        max1++;
	        if(max1>length){
	            length=max1;
	            pos1=i;
	        }
	    }else if(count==0){
	        max1++;
	        if(max1>length){
	            length=max1;
	            pos1=i;
	        }
	        max1=0;
	    }
	}
	cout<<max<<" "<<first_pos<<" "<<length<<" "<<(pos1-length+1);
	return 0;
}
