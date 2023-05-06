#include<iostream>
using namespace std;
#define n 5
//const int n=5;
class queue{
    public:

    int* arr;
    int fr;
    int bc;

    queue(){
        arr = new int[n];
        fr = -1;
        bc = -1;
        //n=5;

    }
    void push(int x){
        if(bc == n-1){
            cout<<"Queue is overflow"<<endl;
            return;
        }
        bc++;
        arr[bc] = x;
        if(fr == -1){
            fr++;
        }
       
    }
    void pop(){
        if(fr == -1 || fr > bc){
            cout<<"Queue is empty"<<endl;
            return;
        }
        fr++;
    }
    int peek(){
        if(fr == -1 || fr>bc){
            cout<<"Queue is empty"<<endl;
            return -1;

        }
        return arr[fr];
    }
    bool empty(){
        if(fr == -1 || fr>bc){
            return true;
        }
        return false;
    }
    void display(){
        if(fr == -1){
            cout<<"queue is empty "<<endl;
        }
        else{
            cout<<"elements are  : ";
            for(int i = fr;i<=bc;i++){
                cout<<arr[i]<<"--";
            }
            cout<<"|\n";
        }
    }
};
int main(){
	int ch;
	int ele;
    queue q;
    /*
    cout<<q.empty()<<endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.peek()<<endl;
    q.display();
    q.pop();
    q.empty();
    cout<<q.peek()<<endl;
    q.display();
    */
    do{
	
	cout<<"1.push\n2.pop\n3.peek\n4.display\n5.empty\n6.exit\nEnter choice : ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"enter elements : ";
			cin>>ele;
			q.push(ele);
			break;
		case 2:
			q.pop();
			break;
		case 3:
			cout<<q.peek()<<endl;
			break;
		case 4:
			q.display();
			break;
		case 5:
			cout<<q.empty()<<endl;
			break;	
		case 6:
			exit(0);
			break;
		default :
			cout<<"invalide choice :\n";					
		
	}
}
	while(true);
    return 0;
}
