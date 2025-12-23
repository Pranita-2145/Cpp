#include <iostream>
using namespace std;

struct Student{
    int roll;
    string name;
    Student(int r, string n)
    {
        roll=r;
        name=n;
    }
};

struct HashMap{
    int key;
    Student * value;
    HashMap * next;
    
    HashMap(int k, Student * v){
        key = k;
        value = v;
        next = NULL;
    }
};

class Hash{
    private :
    HashMap ** table;
    static const int TABLE_SIZE = 11;
    int size;
    
    public :
    Hash(){
        size = 0;
        table = new HashMap *[TABLE_SIZE]();
        for(int i=0; i<TABLE_SIZE; i++){
            table[i] = NULL;
        }
    }
    
    int hashFunction(int key){
        return key % TABLE_SIZE;
    }
    
    void insert(int key, int roll, string n){
        int index = hashFunction(key);
        HashMap * current = table[index];
        HashMap * newNode = new HashMap(key, new Student(roll, n));
        
        newNode->next = table[index];
        table[index] = newNode;
        size++;
        cout<<"Inserted"<<n<<" "<<" "<<roll<<key<<endl;
    }
    
    void display(){
        for(int i=0; i<TABLE_SIZE; i++){
            if(table[i] != NULL){
                HashMap * current = table[i];
                while(current != NULL){
                    cout<<"key ="<<current->value->roll<<current->value->name<<endl;
                    current = current->next;
                }
            }
        }
    }
    
    bool search(int key){
        int index = hashFunction(key);
        HashMap * current = table[index];
        while(current != NULL){
            if(current->key == key){
                cout<<"Found: "<<key<<current->value->roll<<","<<current->value->name<<endl;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    void DisplayMenu(){
        cout<<"1. Insert in Hashmap"<<endl;
        cout<<"2. Display Hashmap"<<endl;
        cout<<"3. Srach using key"<<endl;
    }
};

int main(){
    Hash h;
    int key;
    int choice;
    int roll;
    string name;
    do{
        h.DisplayMenu();
        cout<<"Enter choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                  cout<<"Enter  key"<<endl;
                  cin>>key;
                  cout<<"Enter Rollno"<<endl;
                  cin>>roll;
                  cout<<"Enter name"<<endl;
                  cin>>name;
                  h.insert(key,roll,name);
                  break;
            case 2:
                  h.display();
                  break;
            case 3:
                  cout<<"Enter key"<<endl;
                  cin>>key;
                  h.search(key);
                  break;
        }
        
    }
    while(choice != 14);
    
}
