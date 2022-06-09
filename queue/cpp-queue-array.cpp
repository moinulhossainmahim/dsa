#include<iostream>

using namespace std;

class Queue {
    private:
        int size;
        int rear;
        int front;
        int *Q;
    public:
        Queue()
        {
            size=10;
            front=rear=-1;
            Q=new int[size];
        }
        Queue(int size)
        {
            front=rear=-1;
            this->size=size;
            Q=new int[this->size];
        }
        void enqueue(int x);
        int dequeue();
        void display();
        int isEmpty();
        int isFull();
};

int Queue::isEmpty() {
    return rear==front?1:0;
}

int Queue::isFull() {
    return rear==size-1?1:0;
}

void Queue::enqueue(int x) {
    if(isFull())cout<<"Queue is Full"<<endl;
    else
    {
        rear++;
        Q[rear]=x;
    }
}

int Queue::dequeue() {
    int x=-1;
    if(isEmpty())cout<<"Queue is Empty"<<endl;
    else
    {
        front++;
        x=Q[front];
    }
    return x;
}

void Queue::display() {
    int i=front+1;
    for(; i<=rear; i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<q.dequeue()<<endl;
    q.display();
    printf("%d\n", q.isEmpty());
}
