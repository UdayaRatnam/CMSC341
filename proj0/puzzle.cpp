#include "puzzle.h"
Puzzle::Puzzle(int size){
    // *************************************
    // Implement the alternative constructor
    // *************************************
    //This condition checks to make sure
    //the size entered is not a negative number
    //if it is a negative number it sets m_size to zero
    if(size <= 0){
        m_size = 0;
    }
    else{
        
        m_size = size;
        makeMem();
        fill();
    }
    
}
Puzzle::~Puzzle(){
    clear();
    
}
void Puzzle::clear(){
    // ***************************
    // Implement clear() function
    // ***************************
    if(m_size > 0){
        for(int i = 0; i < m_size; i++){
            delete[] m_table[i];//deallocates array
        }
        delete[] m_table;//deallocates whole 2d array
        m_size = 0;
    }
    

    
}
void Puzzle::makeMem(){
    // ****************************
    // Implement makeMem() function
    // ****************************
    //Checks to make sure the size is greater than 0
    //If it is then it allocates a new m_table
    if (m_size > 0){

        m_table = new char*[m_size];
        for(int i = 0; i < m_size;i++){
            m_table[i] = new char[m_size];
        }
    }
   
    
}
Puzzle::Puzzle(const Puzzle& rhs){
    // ***************************
    // Implement copy constructor
    // ***************************
    //Copies all the members in the puzzle class
 
    m_size = rhs.m_size;
    
   
    makeMem();

    for(int i = 0; i < m_size; i++){      
        for(int j = 0; j < m_size; j++){
            m_table[i][j] = rhs.m_table[i][j];
        }
    }
    
  
}
const Puzzle& Puzzle::operator=(const Puzzle& rhs){
    // *****************************
    // Implement assignment operator
    // *****************************
    //This conditional is a self-guard to
    //prevent the program from crashing if an object = object in the program
    if(this != &rhs){
        clear();
        this->m_size = rhs.m_size;
        this->m_table = new char*[m_size];
        for(int i = 0; i < m_size; i++){
            this->m_table[i] = new char [m_size];
        }

        for(int i = 0; i < m_size; i++){
            for(int j = 0; j < m_size; j++){
                this->m_table[i][j] = rhs.m_table[i][j];
            }
        }
    }
    
    return *this;

}
void Puzzle::dump(){
    if (m_size > 0){
        int i=0;
        int j=0;
        while(i<m_size){
            while(j<m_size){
                cout << m_table[i][j] << " ";
                j++;
            }
            cout << endl;
            j=0;
            i++;
        }
        cout << endl;
    }
}
void Puzzle::fill(){
    srand(time(NULL));//create the seed value using the current time
    int i=0;
    int j=0;
    while(i<m_size){
        while(j<m_size){
            m_table[i][j] = ALPHA[rand() % MAX];//find a random char from the chars list
            j++;
        }
        j=0;
        i++;
    }
}