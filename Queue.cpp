#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

class Queue{
    private:
    Node * front=NULL;
    Node * rear=NULL;
    public:
    
    bool isEmpty(){
        return front==NULL;
    }
    void Enqueue(int data){
        Node * newNode = new Node(data);
        if(rear==NULL || front==NULL){
            front = newNode;
            rear=newNode;
            return;
        }
        else{
            rear->next = newNode;
            rear = newNode;

        }
    }
    
    void Dequeue(){
        Node * temp = front;
        if(isEmpty()){
            cout<<"Empty Queue"<<endl;
            return;
        }
        else{

            front = front->next;
            cout<<"Deleted Sucessfully: "<<temp->data<<endl;
            delete temp;
        }
    }
    
    void Display(){
        Node * temp = front;
        if(isEmpty())
        {
            cout<<"Empty"<<endl;
        }
        
        while(temp != NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
};

void displayMenu(){
    cout<<"1. Enqueue"<<endl;
    cout<<"2. Dequeue"<<endl;
    cout<<"3.Display Queue"<<endl;
}

int main(){
    Queue q;
    int choice;
    int val;
    do{
        displayMenu();
        cout<<"Enter choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                  cout<<"Enter value:"<<endl;
                  cin>>val;
                  q.Enqueue(val);
                  break;
            case 2:
                  q.Dequeue();
                  break;
            case 3:
                 q.Display();
                  break;
            default:
                 "Invalid choice";
        }
    }while(choice != 5);
}
