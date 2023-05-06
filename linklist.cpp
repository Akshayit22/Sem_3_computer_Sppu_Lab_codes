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
void insertattail(node* &head,int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return ;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;
}
void insertathead(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}
bool search(node* head,int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;

}
//reversing a linked list
//1.recursive way
node* recursiverev(node* &head){
    if(head == NULL || head->next==NULL){
        return head;
    }
    node* newhead = recursiverev(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
//2.iterative way
node* reverseitr(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    } 
    return prevptr;  
}
void deleteathead(node* &head){
    node* todetele = head;
    head = head->next;
    delete todetele;
}
void deletion(node* &head,int val){
    if(head == NULL)
        return;
    if(head->next == NULL){
        deleteathead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    //to delete temp->next node
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
int main(){
    node* head = NULL;
    int ele;
    /*
   // insertathead(head,100);
    insertattail(head,10);
    insertattail(head,20);
    insertattail(head,30);
    insertattail(head,40);
    insertattail(head,50);
   //	display(head);
    //insertathead(head,200);
    //display(head);
    //cout<<search(head,150);
    //recursiverev(head);
	display(head);
   // deleteathead(head);
   // deletion(head,30);
    //deletion(head,20);
    reverseitr(head);
   	display(head);
   	*/
   	int ch;
   	do{
	   
	   	cout<<"1.to insert at tail\n2.to insert at head\n3.to search\n.4to traverse(recurcive)"<<endl;
	   	cout<<"5.traverse(iterative)\n6.to delete\n7.to exitn\nEnter choice: ";
	   	
	   	cin>>ch;
	   	
	   	switch(ch){
	   		case 1:
	   			cout<<"enter element : ";
	   			cin>>ele;
	   			insertattail(head,ele);
			   break;
			case 2:
				cout<<"enter element : ";
	   			cin>>ele;
				insertathead(head,ele);
			   break;
			case 3:
				cout<<"enter element : ";
	   			cin>>ele;
				search(head,ele);
			   break;
			case 4:
				recursiverev(head);
			   break;
			case 5: 
				reverseitr(head);
			case 6:
				cout<<"enter element : ";
	   			cin>>ele;
				deletion(head,ele);
			   break;
			case 7: 
				exit(0);
				break;
			default:
					cout<<"invalid choice"<<endl;
					
		}
	}while(ch == 6);
    return 0;
    
}
