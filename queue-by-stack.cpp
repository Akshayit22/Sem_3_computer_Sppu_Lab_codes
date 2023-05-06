#include<iostream>
#include<stack>
using namespace std;
class queue{
    public:
    stack<int>s1;
    stack<int>s2;

    void push(int x){
        s1.push(x);
    }
    int pop(){
        while(s1.empty() && s2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }
    //top function is not working 
    int top(){
        int topval = s2.top();
        //cout<<topval;
        //s2.pop();
        return topval;
    }
    bool empty(){
        if (s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};
int main(){
    queue q;
    cout<<q.empty()<<endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.empty()<<endl;
   // cout<<q.top()<<endl;
    q.pop();
   // q.pop();
    cout<<q.top()<<endl;

    return 0 ;
}
