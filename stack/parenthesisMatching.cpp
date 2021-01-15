#include<bits/stdc++.h>
using namespace std;
bool checkParanthesis(string equation){
		
	stack<char> s;
		for(int i=0;i<equation.size();i++){
		if(equation[i]=='{'||equation[i]=='[' ||equation[i]=='('){
			s.push(equation[i]);
			if(s.empty()) return false;
		}else if(equation[i]=='}'){
			if(s.top()=='{'){
				s.pop();
			}else{
				return false;
				break;

			}	
		}else if(equation[i]==']'){
			if(s.top()=='['){
				s.pop();
			}else{
				return false;
				break;

			}	
		}else if(equation[i]==')'){
			if(s.top()=='('){
				s.pop();
			}else{
				return false;
				break;

			}	}
	}
	return s.empty();
}

int main(){
	
	string equation;
	getline(cin,equation);
	
	checkParanthesis(equation)?cout<<"Matched":cout<<"Not matched";
	return 0;
}

