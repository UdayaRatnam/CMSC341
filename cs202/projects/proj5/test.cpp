#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Test {
    int x, y; 
    public:
        Test(int a , int b){
            x = a;
            y = b;
        }
        friend ostream& operator <<(ostream& os, const Test& t);
    
};

ostream& operator<<(ostream& os, const Test& t){
    os << t.x << t.y;
    return os;
}


int main(){
    bool notFive = true;
    int choice;
    
    do{
        cout<<"What would you like to do?"<<endl;
        cout<<"1. Display Media by Type and Year"<<endl;
        cout<<"2. Add Media to Playlist"<<endl;
        cout<<"3. Display Playlist"<<endl;
        cout<<"4. Sort Playlist by Year"<<endl;
        cout<<"5. Quit"<<endl;
        cin >> choice;
        switch(choice){
            case 1:
                cout<<"Displays Media"<<endl;
                break;
            case 2:
                cout<<"Add Media"<<endl;
                break;
            case 3:
                cout<<"Display Playlist"<<endl;
                break;
            case 4:
                cout<<"Sort Playlist"<<endl;
                break;
            case 5:
                cout<<"Thank you thats it"<<endl;
                notFive = false;
                break;
            default:
                break;
        }
    }while((choice  > 1 || choice <  5) && notFive);
    cout<<choice<<endl;
    
        
}