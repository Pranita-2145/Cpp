#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
    Node(int value){
        next =NULL;
        data = value;
    }
};
 
    class Stack{
        private: Node * top;
        public :
        Stack(){
            top = NULL;
        }
 
 
    bool isEmpty(){
        return top == NULL;
    }
 
    void push(int value){
        Node * newNode = new Node(value);
        if(isEmpty()){
            top = newNode;
            return;
        }
        else{
            newNode->next = top;
            top = newNode;
            cout<<"Pushed sucessfully"<<value<<endl;
        }
 
    }
 
    void pop(){
        Node * temp;
        if(isEmpty()){
            return;
        }
        else{
            temp = top;
            top = top->next;
 
            cout<<"Poped sucessfully"<<temp->data<<endl;
             delete temp;
        }
 
    }
 
    void peek(){
        Node * temp = top;
        cout<<"The top of stack is: "<<temp->data<<endl;
    }
 
    void display(){
        Node * temp = top;
        while(temp != NULL){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
 
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }
    };
 
    void displayMenu(){
        cout<<"1.Push in Stack"<<endl;
        cout<<"2. Pop from stack"<<endl;
        cout<<"3. Peek- Top of stack"<<endl;
        cout<<"4. Display all stack"<<endl;
    }
 
    int main(){
        Stack s;
        int choice;
        int value;
        do{
            displayMenu();
            cout<<"Enter choice:"<<endl;
            cin>>choice;
            switch(choice){
                case 1:
                        cout<<"Enter value"<<endl;
                        cin>>value;
                        s.push(value);
                        break;
                case 2:
                      s.pop();
                      break;
 
                case 3:
                      s.peek();
                      break;
                case 4:
                     s.display();
                     break;
                default:
                     "Invalid choice";
 
 
 
            }
        }while(choice != 10);
    }
