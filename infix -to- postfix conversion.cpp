#include<iostream>
#include<stack>
using namespace std;

// giving current prec of current element
int prec(char c){
	if(c=='*' || c=='/'){
		return 2;
		
	}
		if(c=='+' || c=='-'){
		return 1;
		
	}
	else{
		return -1;    //when opening brackets came
	}
}

string infixtopostfix(string s){
	stack<char> st;
	string r; //result
	for(int i=0;i<s.length();i++){
		if((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&& s[i]<='Z') || isdigit(s[i])){
			r=r+s[i];
		}
	
	else if(s[i]=='('){
		st.push(s[i]);
	}
	else if(s[i]==')'){
		while(!st.empty() && st.top()!='('){
			r=r+st.top();
			st.pop();
		}
		if(!st.empty()){
			st.pop();
		}
		
		
	}
	else{
		while(!st.empty() && prec(st.top())>prec(s[i])){
			r=r+st.top();
			st.pop();
		}
		st.push(s[i]);
	}
	
}
while(!st.empty()){
	r=r+st.top();
	st.pop();
}
return r;
}
int evaluation(string s){
	stack<int> st;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]-'0');
		}
		else{
			int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();
			switch(s[i]){
				case'+':
					st.push(op1+op2);
					break;	
				case '-':
					st.push(op1-op2);
					break;
				case '*':
					st.push(op1*op2);
					break;
				case'/':
					st.push(op1/op2);
					break;
			}
		}
	}
	return st.top();
}
int main(){
	string i = "6+2*7/2-9";
	cout<<"Infix expression is: "<<i<<endl; 
	string p = infixtopostfix(i);
	cout<<"Infix Expression to postfix expression is: ";
	cout<<p<<endl;
	cout<<"Result: ";
	cout<<evaluation(p)<<endl;
	
	return 0;
}
