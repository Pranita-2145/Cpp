#include <iostream>
#include <queue>
using namespace std;

struct EdgeNode{
    int vertex;
    EdgeNode * next;
    EdgeNode(int v){
        this->vertex = v;
        next = NULL;
    }
    
};

class Graph{
    private:
    EdgeNode ** l;
    int v;
    int * visited;
    queue<int>Q;
    
    
    public:
    Graph(int v){
        this->v = v;
        l = new EdgeNode * [v];
        for(int i=0; i<v; i++){
            l[i] = NULL;
        }
        visited = new int[v];
    }
    
    void addEdge(int u, int v){
        EdgeNode * newNode = new EdgeNode(v);
        newNode->next = l[u];
        l[u] = newNode;
        
        EdgeNode * reverseNode = new EdgeNode(u);
        newNode->next = l[v];
        l[v] = reverseNode;
    }
    
    void display(){
        for(int i=0; i<v; i++){
            cout<<"vertex: "<<i<<":"<<endl;
            EdgeNode * curr = l[i];
            while(curr != NULL){
                cout<<curr->vertex<<" ";
                curr = curr->next;
            }
            cout<<endl;
        } 
    }
    
    void displayMenu(){
        cout<<"1. Add to graph"<<endl;
        cout<<"2.Display from graph"<<endl;
        cout<<"3.BFS"<<endl;
        
    }
    
    void BFS(int start){
        Q.push(start);
        visited[start] = 1;
        while(!Q.empty()){
            int current = Q.front();
            cout<<current<<",";
            Q.pop();
            EdgeNode * neighbor = l[current];
            while(neighbor != NULL){
                if(!visited[neighbor->vertex]){
                    visited[neighbor->vertex]=1;
                    Q.push(neighbor->vertex);
                }
                neighbor = neighbor->next;
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph g(5);
    int choice;
    int u;
    int v;
    int start;
    do{
        g.displayMenu();
        cout<<"Enter choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                 cout<<"Enter value of u"<<endl;
                 cin>>u;
                 cout<<"Enter value of v"<<endl;
                 cin>>v;
                 g.addEdge(u,v);
                 break;
            case 2:
                  g.display();
                  break;
            case 3:
            cout<<"Enter value to start"<<endl;
            cin>>start;
                 g.BFS(start);
            default:
             "invalid";
        }
    }
    while(choice != 20);
}
