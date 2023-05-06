#include<iostream>
using namespace std;
//display function not working
class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertathead(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    if(head !=NULL){
        head->prev = n;
    }
    head = n;
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;
}
void insertattail(node* &head,int val){
    node* n = new node(val);
    node* temp = head;

    while(temp->next = NULL){
        temp = temp->next;

    }
    temp->next = n;
    n->prev = temp;
    if (head == NULL){
        insertathead(head , val);
        return;
    }
}
void deleteathead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletion(node* &head,int pos){
    if(pos == 1){
        deleteathead(head);
        return ;
    }
    node* temp = head;
    int count=1;
    while(temp != NULL && count != pos){
        temp =temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
}
int main(){
     node* head = NULL;
     cout<<"hello \n";
   // insertathead(head,100);
    insertattail(head,10);
    insertattail(head,20);
    insertattail(head,30);
    insertattail(head,40);
    insertattail(head,50);
    display(head);


    return 0;
}
