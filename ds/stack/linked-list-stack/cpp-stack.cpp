#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class Stack
{
    private:
        Node *top;
    public:
        Stack() {
            top=NULL;
        }
        void push(int x);
        int pop();
        void display();
        int isEmpty();
};

void Stack::push(int x) {
    Node *t=new Node;

    if(t==NULL)cout<<"Stack is Full"<<endl;
    t->data=x;
    t->next=top;
    top=t;
}

int Stack::pop() {
    int x=-1;
    Node *t=top;
    if(t==NULL)cout<<"Stack is Empty"<<endl;
    top=top->next;
    x=t->data;
    delete t;
    return x;
}

void Stack::display() {
    Node *t=top;
    while(t!=NULL) {
        cout<<t->data<<" ";
        t=t->next;
    }
}

int Stack::isEmpty() {
    return top?0:1;
}

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    cout<<"Popped value is: "<<s.pop()<<endl;
    int isEmpty = s.isEmpty();
    if(isEmpty)cout<<"Stack is Empty"<<endl;
    else cout<<"Stack is not Empty"<<endl;
}

