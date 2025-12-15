#include <iostream>

using namespace std;

struct Student{
    int id;
    char name[50];
    float gpa;
}s[10];

void addnew();
void display();
void displaymenu();
void findmax();
void findavg();
void search();
int n;

int main() {
int choice;
do{
    displaymenu();
    cout<<"Enter choice"<<endl;
    cin>>choice;
   
    switch(choice){
        case 1:
            cout<<"Enter number of entries"<<endl;
            cin>>n;
             addnew();
             break;
        case 2:
            
             display();
             break;
        case 3: 
             findmax();
             break;
        case 4:
             findavg();
             break;
        case 5:
             search();
             break;
        case 6:
             return 0;
        default:
             "Invalid Input";
    }
    
}
while(choice != 3);
}

void addnew(){
    int i;
    for(i=0; i<n; i++){
    cout<<"Enter ID"<<endl;
    cin>>s[i].id;
    
    cout<<"Enter Name"<<endl;
    cin>>s[i].name;
    
    cout<<"Enter GPA"<<endl;
    cin>>s[i].gpa;
    
}
}

void display(){
    int i;
    for(i=0; i<n; i++){
    cout<<"Student is"<<endl;
    cout<<s[i].id<<endl;
    cout<<s[i].name<<endl;
    cout<<s[i].gpa<<endl;
}
}

void displaymenu(){
    cout<<"1. Add new Entry"<<endl;
    cout<<"2. Display values"<<endl;
    cout<<"3. Find highest gpa"<<endl;
    cout<<"4. Find average of all gpa"<<endl;
    cout<<"5. Search by ID"<<endl;
}
void findmax(){
    int max =0;
    int i;
    for(i =0; i<n; i++){
        if(s[i].gpa > max){
            max = s[i].gpa;
        }
    }
    cout<<"The highest gpa scored is"<<endl;
    cout<<max;
}

void findavg(){
    int sum=0;
    int avg;
    int i;
    for(i=0; i<n; i++){
        sum += s[i].gpa;
    }
    avg = sum /n;
    cout<<"The average of all gpa is:"<<endl;
    cout<<avg<<endl;
}

void search(){
    int key;
    cout<<"Enter the ID to serach"<<endl;
    cin>>key;
    int i;
    for(i=0; i<n; i++){
        if(key == s[i].id){
            cout<<"ID Present"<<endl;
        }
    }
    
}



Array Structure with pointer - 
#include <iostream>
using namespace std;
struct Student{
    int id;
    char name[50];
    int gpa;
}*s;
void displaymenu();
void addnew(struct Student *, int n);
void display(struct Student *, int n);
int main(){
    int choice;
    int n=10;
    s =new Student[10];
    do{
       displaymenu();
       cout<<"Enter choice"<<endl;
       cin>>choice;
       switch(choice){
           case 1:
                 addnew(s,n);
                 break;
            case 2:
                 display(s,n);
                 break;
            case 3:
                 return 0;
            default:
                 "Invalid";
                 
       }
    }
    while(choice != 3);
}

void displaymenu(){
    cout<<"1.Add new Entry"<<endl;
    cout<<"2.Display"<<endl;
    
}

void addnew(struct Student *s, int n){
    int i;
    
    for(i=0; i<n; i++){
        cout<<"Enter ID"<<endl;
        cin>>s[i].id;
        cout<<"Enter name"<<endl;
        cin>>s[i].name;
        cout<<"Enter GPA"<<endl;
        cin>>s[i].gpa;
    }
}

void display(struct Student *s, int n){
    int i;
    for(i=0; i<n; i++){
        cout<<s[i].id<<endl;
        cout<<s[i].name<<endl;
        cout<<s[i].gpa<<endl;
    }
}
