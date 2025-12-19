#include <iostream>
using namespace std;

class BT{
    private:
    struct Node{
        int data;
        Node * left;
        Node * right;
        Node(int value){
            data =  value;
            left = NULL;
            right = NULL;
        }
    };
    
    Node * insertRecursive(Node * node, int value){
        if(node == NULL){
            return new Node(value);
        }
        if(value<node->data){
            node->left = insertRecursive(node->left,value);
        }
        else{
            node->right = insertRecursive(node->right,value);
        }
         return node;
    }
   
   void inorderRecursive(Node * temp){
       if(temp !=NULL){
           inorderRecursive(temp->left);
           cout<<temp->data<<endl;
           inorderRecursive(temp->right);
       }
   }
    
    public:
        Node * root = NULL;

    void insert(int value){
        root = insertRecursive(root,value);
        cout<<"Node inserted sucessfully"<<endl;
    }
    
    void DisplayMenu(){
        cout<<"1. Insert in Tree"<<endl;
        cout<<"2.Display"<<endl;
    }
    
    void Display(){
        inorderRecursive(root);
    }
};

int main(){
    int value;
    int choice;
    BT b;
    do{
        b.DisplayMenu();
        cout<<"Enter choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                  cout<<"Enter value"<<endl;
                  cin>>value;
                  b.insert(value);
                  break;
            case 2:
                 b.Display();
                 break;
            default:
                "Invalid choice";
        }
    }while(choice != 4);
}

