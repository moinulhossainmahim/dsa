#include<iostream>
using namespace std;

class Queue {
  private:
    int front;
    int rear;
    int arr[5];
  
  public:
    Queue() {
      front = -1;
      rear = -1;
      for(int i=0; i<5; i++) {
        arr[i] = 0;
      }
    }

    bool isEmpty() {
      if(front == -1 && rear == -1) {
        return true;
      } else {
        return false;
      }
    }

    bool isFull() {
      if(rear == 4) {
        return true;
      } else {
        return false;
      }
    }

    void enqueue(int value) {
      if(isFull()) {
        cout<<"Queue is Full"<<endl;
        return;
      } else if(isEmpty()) {
        rear = 0;
        front = 0;
      } else {
        rear++;
      }
      arr[rear] = value;
    }

    int dequeue() {
      int x;
      if(isEmpty()) {
        cout<<"Queue is Empty."<<endl;
        return 0;
      } else if(rear == front) {
        x = arr[front];
        arr[front] = 0;
        front = -1;
        rear = -1;
        return x;
      } else {
        x = arr[front];
        arr[front] = 0;
        front++;
        return x;
      }
    }

    int count() {
      return (rear - front + 1);
    }

    void display() {
      cout<<"All values in the Queue are - "<<endl;
      for(int i=0; i<5; i++) {
        cout<<arr[i]<<" ";
      }
    }
};

int main() {
  Queue q1;
  int option, value;
  do {

    cout<<"\n\nWhat operation do you want to perform? Select Option Number. Enter 0 to exit."<<endl;
    cout<<"1. Enqueue()"<<endl;
    cout<<"2. Dequeue()"<<endl;
    cout<<"3. isEmpty()"<<endl;
    cout<<"4. isFull()"<<endl;
    cout<<"5. count()"<<endl;
    cout<<"6. display()"<<endl;
    cout<<"7. Clear Screen"<<endl<<endl;

    cin>>option;    

    switch(option) {
      case 0:
        break;
      case 1:
        cout<<"Enqueue Operation \nEnter an item to Enqueue in the Queue"<<endl;
        cin>>value;
        q1.enqueue(value);
        break;
      case 2:
        cout<<"Dequeue operation \n Dequeued Value: "<<q1.dequeue()<<endl;
        break;
      case 3:
        if(q1.isEmpty()) {
          cout<<"Queue is Empty"<<endl;
        } else {
          cout<<"Queue is not Empty"<<endl;
        }
        break;
      case 4:
        if(q1.isFull()) {
          cout<<"Queue is Full"<<endl;
        } else {
          cout<<"Queue is not Full"<<endl;
        }
        break;
      case 5:
        cout<<"Count operation \nCount of items in Queue: "<<q1.count()<<endl;
        break;
      case 6:
        cout<<"Display function called"<<endl;
        q1.display();
        break;
      case 7:
        system("cls");
        break;
      default:
        cout<<"Enter Proper option number "<<endl;
        break;
    }

  } while(option != 0);

  return 0;
}
