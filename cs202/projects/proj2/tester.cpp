
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include "Game.h"
using namespace std;



int main(){
    
    srand(time(NULL));
    int rand_int = 1 + rand() % 100 < 43;
    for(int i = 1; i < 100; i++){
        rand_int = rand() % 100 < 43;
        cout<<rand_int<<endl;
        
    }



    cout<<rand_int<<endl;
    


    
    
    return 0;

}
