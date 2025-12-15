#include <iostream>
using namespace std;

struct Node * head = NULL;
struct Node{
    int data;
    Node * next;
    Node * prev;
    Node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }
};

struct Node * insertFront(int data){
   struct  Node * temp = new Node(data);
   if(head == NULL){
       head = temp;
   }
   else{
       temp->next = head;
       head->prev = temp;
       head = temp;
      
   }
   return head;
}

struct Node * insertEnd(int data){
    struct Node * newNode = new Node(data);
    Node * temp;
    if(head == NULL){
        head = temp;
    }
    else{
        temp = head;
        while(temp->next != NULL){
        temp=temp->next; 
    }
        temp->next = newNode;
        newNode->prev = temp;
        
    }
    return head;
}

struct Node * deleteFront(int data){
    Node * temp = head;
    if(temp == NULL){
        cout<<"List Empty"<<endl;
    }
    else{
        head = temp->next;
        head->prev = NULL;
        temp = NULL;
    }
    return head;
}

struct Node * deleteEnd(int data){
    Node * temp = head;
    if(temp == NULL){
        cout<<"List Empty"<<endl;
        
    }
    else{
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        
        temp->next->prev = NULL;
        temp->next = NULL;
    }
    return head;
}
void display(){
    Node * temp = head;
    if(head == NULL){
        cout<<"Empty list"<<endl;
    }
    else{
    while(temp != NULL){
        cout<<temp->data<<endl;
         temp=temp->next;
    }
   
}
}

void displayMenu(){
    cout<<"1. Add in front"<<endl;
    cout<<"2.Display List"<<endl;
    cout<<"3. Add in End"<<endl;
    cout<<"4. Delete Front"<<endl;
    cout<<"5.Delete at End"<<endl;
}
int main(){
    int choice;
    int value;
    do{   
        displayMenu();
        cout<<"Enter choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                   cout<<"Enter value"<<endl;
                   cin>>value;
                   head = insertFront(value);
                   break;
            case 2:
                  display();
                  break;
            case 3:
                 cout<<"Enter value"<<endl;
                 cin>>value;
                 head = insertEnd(value);
                 break;
            case 4:
                  deleteFront(value);
                  break;
            case 5:
                  deleteEnd(value);
                  break;
            default:
                   "Invalid choice";
                   
        }
    }while(choice != 10);
    
}
