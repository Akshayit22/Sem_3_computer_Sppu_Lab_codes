#include<iostream>
#include<queue>
using namespace std;
class stack{
    public:
    queue<int>q;

    void push(int x){
        queue<int>temp;
        temp.push(x);
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        swap(q,temp);
    }
    void pop(){
        q.pop();
    }
    int top(){
        return q.front();
    }
    int empty(){
        return q.empty();
    }

};
int main(){
    stack s;
    cout<<s.empty()<<endl;
    //cout<<s.pop()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;

    return 0;
}