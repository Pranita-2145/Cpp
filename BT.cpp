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
   
   void preorderRecursive(Node * node){
       if(node != NULL){
           cout<<node->data<<endl;
           preorderRecursive(node->left);
           preorderRecursive(node->right);
       }
   }
   
   void postorderRecursive(Node * node){
       if(node != NULL){
           postorderRecursive(node->left);
           postorderRecursive(node->right);
           cout<<node->data<<endl;
       }
   }
    //Search using Key
    
    bool SearchRecursive(Node * node, int value){
        if(node == NULL) return false;
        if(node->data == value) return true;
        return(node->data > value)?
        SearchRecursive(node->left,value):
        SearchRecursive(node->right,value);
    }
    
    //Height 
    
    int heightRecursive(Node * node){
        if (node==NULL) return 0;
        return 1 + max(heightRecursive(node->left), heightRecursive(node->right));
    }
    
    public:
        Node * root = NULL;

    void insert(int value){
        root = insertRecursive(root,value);
        cout<<"Node inserted sucessfully"<<endl;
    }
    
    void DisplayMenu(){
        cout<<"1. Insert in Tree"<<endl;
        cout<<"2.Display Inorder"<<endl;
        cout<<"3.Display Preorder"<<endl;
        cout<<"4.Display Postorder"<<endl;
        cout<<"5. Search using Key"<<endl;
        cout<<"6.Height of tree"<<endl;


    }
    
    void DisplayInorder(){
        inorderRecursive(root);
    }
     void DisplayPreorder(){
        preorderRecursive(root);
    }
     void DisplayPostorder(){
        postorderRecursive(root);
    }
    
    void Search(int value){
        bool found = SearchRecursive(root, value);
        cout<<"Searched value: "<<value<<(found?"Found":"Not found")<<endl;
        
        
    }
    
    void height(Node * node){
        int h=heightRecursive(node);
        cout<<"The height is: "<<h<<endl;
    }
   
};

int main(){
    int value;
    int choice;
    int key;
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
                 b.DisplayInorder();
                 break;
            case 3:
                b.DisplayPreorder();
                break;
            case 4:
                b.DisplayPostorder();
                break;
            case 5:
                cout<<"Enter Key"<<endl;
                cin>>key;
                b.Search(key);
                break;
            case 6:
                b.height(b.root);
                break;
                
            default:
                "Invalid choice";
        }
    }while(choice != 10);
}

