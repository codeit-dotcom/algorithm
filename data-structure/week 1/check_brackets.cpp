#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
	string text;
	cin>>text;
	int i, a,balance=1;
	stack <char> ch;
	for( i=0;i<text.length();i++){
		if (ch.empty())
		    	a=i;
		char c=text[i];
	  if(c=='(' || c=='['||c=='{'){
            ch.push(c);
	    }
	  if(c==')'|| c==']' ||c=='}'){
		   if(ch.empty())
		   { balance=0;
		   break;}
		   char top=ch.top();
		   ch.pop();
		   if((top=='('&& c!=')' ) || (top=='['&& c!=']') || (top=='{'&& c!='}'))
            {balance=0;
			break;}
	    }

	}
 if(balance&&ch.empty()){
	 cout<<"Success";
 }
 else{
         if((i>=text.size())&&!ch.empty())
			cout<<a+1<<endl;
		else
			cout<<i+1<<endl;
 }
 return 0;
}