#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
       
    }
};
void display(node* head){
    node* temp = head;
    do{
        cout<<temp->data<<"-->";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}
void insertathead(node* &head,int val){
    node* n = new node(val);
    if(head !=NULL){
        n->next != head;
        head = n;
        return ;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;

    }
    temp->next = n;
    n->next =head;
    head = n;
    
}
void insertattail(node* &head,int val){
    if (head == NULL){
        insertathead(head , val);
        return;
    }
    node* n = new node(val);
    node* temp = head;

    while(temp->next != head){
        temp = temp->next;

    }
    temp->next = n;
    n->next = head;
    
}
int main(){
    node*head =NULL;
    insertattail(head , 10);
    insertattail(head , 20);
    insertattail(head , 30);
    insertattail(head , 40);
    insertattail(head , 50);

    display(head);

    return 0;
}