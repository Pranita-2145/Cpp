#include <iostream>
using namespace std;
const float pie = 3.14;
inline float carea(int r){
    return pie * r * r;
}
int main(){
    enum shape{
        circle,
        rectangle,
        square,
    };
    int type;
    int Area;
    int s;
    int l,b;
    int r;
        cout<<"Enter type(Circle: 0, Rectangle 1, Square: 2): "<<endl;
        cin>>type;
        switch(type)
        {
            case circle:
            cout<<"Enter radius:"<<endl;
            cin>>r;
            Area = carea(r);
            cout<<"Area is: "<<Area;
            break;
 
            case square:
            cout<<"Enter side: "<<endl;
            cin>>s;
            Area= s * s;
            cout<<"Area is: "<<Area;
            break;
 
            case rectangle:
            cout<<"Enter l: "<<endl;
            cin>>l;
            cout<<"Enter b: "<<endl;
            cin>>b;
            Area = l * b;
            cout<<"Area is: "<<Area;
            break;
 
            default:
              "Invalid selection";
              break;
 
 
        }
 
        return 0;
 
}
