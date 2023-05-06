#include<iostream>
using namespace std;
class stack{
	public:
	int topp = -1;
	int arr[5];
	
	void push(int x){
		if(isfull() == 1){
			return ;
		}
		top++;
		arr[top] = x;
		cout<<"element inserted into stack\n";
		
	}
	
	int pop(){
		if(isempty() == 1){
			return 0;
		}
		int e;
		e = arr[top];
		top--;
		return e;
		
	}
	int isempty(){
		if(top==-1){
			cout<<"underflow condition\n";
			return 1;
		}
		return 0;
	}
	int isfull(){
		if(top==5){
			cout<<"overflow condition\n";
			return 1;
		}
		return 0;
	}
	int gettop(){
		if(isempty() == 1){
			return 0;
		}
		return arr[top];	
	}
	
};
int main(){
	stack s;
	int a;
	s.isempty();
	s.isfull();
	s.gettop();
	for(int i=0;i<6;i++){
		cin>>a;
		s.push(a);
	}
	s.gettop();
	for(int i=0;i<6;i++){
			cout<<s.pop()<<"\t";
	}
	cout<<"exit";
	return 0;
}
