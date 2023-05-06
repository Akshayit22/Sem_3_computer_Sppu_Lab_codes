#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }


};
class queue{
    public:
    node* fr;
    node* bc;

    queue(){
        fr = NULL;
        bc = NULL;
    }

    void push(int x){
        
        if(fr == NULL){
        	node* n = new node(x);
            bc = n;
            fr = n;
            return ;
        }
        node* n = new node(x);
        bc->next =n;
        bc = n;
    }
    void pop(){
        if(fr == NULL){
            cout<<"queue is underflow\n";
            return ;
        }
        node* todelete = fr;
        fr = fr->next;
        delete todelete;
    }
    int peek(){
        if(fr==NULL){
            cout<<"queue is empty\n";
            return -1;
        }
        return fr->data;
    }
    bool empty(){
        if (fr==NULL)
            return true;

        return false;
    }
};
int main(){
    queue q;
    int ele,ch;
    /*
    q.empty();
    q.push(10);
    q.push(20);
    q.push(30);
	q.push(40);
    q.push(100);
    q.pop();
    q.peek();
    q.empty();
    cout<<"hello world";
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
			//q.display();
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
