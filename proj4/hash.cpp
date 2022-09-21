// CMSC 341 - Spring 2021 - Project 4
// hash.cpp
// The impleme ntation of the class HashTable
#include "hash.h"
#include "math.h"
HashTable::HashTable(unsigned size, hash_fn hash){
    
    if(isPrime(size)){
        if(size < MINPRIME){
            m_capacity = MINPRIME;
        }
        if(size > MAXPRIME){
            m_capacity = MAXPRIME;
        }
        else{
            m_capacity = size;
        }
    }
    else{
        size = findNextPrime(size);
        m_capacity = size;
    }
    m_hash = hash;
    m_size = 0;
    m_numDeleted = 0;
    m_currentProb = LINEAR;
    m_table = new Person[m_capacity];
    
    
   
}

HashTable::~HashTable(){
    m_capacity = 0;
    m_size = 0;
    m_numDeleted = 0;
    m_currentProb = LINEAR;
    delete [] m_table;
    m_table = nullptr;


    
}


bool HashTable::insert(Person person){
   
    bool insertType;
    if(m_currentProb == LINEAR){
        insertType =  linearProbingInsert(person);
        if(insertType && lambda() > 0.5){
            cout<<"REHASH AT THIS PERSON "<<person<<endl;
            setProbingPolicy(QUADRATIC);
        }

    }
    else{
        insertType = quadraticProbingInsert(person);
        if(insertType && lambda() > 0.5){
            cout<<"REHASH AT THIS PERSON "<<person<<endl;
            setProbingPolicy(LINEAR);
        }
    }
    
    return insertType;
    
    
   
   
}

void HashTable::reHash(probing currProb){
    cout<<"REHASH IS CALLED"<<endl;
    int numDataPoints = m_size - m_numDeleted;
    //unsigned int newCap = findNextPrime((numDataPoints * 4));
    Person* temp = new Person[numDataPoints];
    unsigned int counter = 0;
    
    for(unsigned int i = 0; i < m_capacity; i++){

        bool isEmpty = (m_table[i] == EMPTY);
        bool isRemoved = (m_table[i] == DELETED);

        if(isEmpty == false && isRemoved == false){

           //cout<<i<<" "<<m_table[i]<<endl;
           temp[counter] = m_table[i];
           counter++;

        }
        
    }
   
    
    delete [] m_table;
    m_table = nullptr;
    m_capacity = findNextPrime( (m_size - m_numDeleted) * 4);
    m_size = 0;
    m_numDeleted = 0;
    m_table = new Person [m_capacity];
    for(int i = 0; i < numDataPoints;i++){

        if(currProb == LINEAR){

            this->linearProbingInsert(temp[i]);
        }
        else{
            this->quadraticProbingInsert(temp[i]);
        }
    }
    delete [] temp;
    temp = nullptr;
    
}
bool HashTable::linearProbingInsert(Person person){
  
  unsigned int index = m_hash(person.key()) % m_capacity;
  bool inserted = false;
  while(!inserted){
      if(m_size == m_capacity){
          cout<<"TABLE IS FULL"<<endl;
          inserted = true;
      }
      else if(m_table[index] == person){
          cout<<"PERSON ALREADY IN HASH TABLE"<<endl;
          return false;
      }
      else if(m_table[index] == EMPTY){
          m_table[index] = person;
          m_size++;
          inserted = true;
      }
      else{

          if(index >= (m_capacity - 1)){
            index = 0;
          }
          else{
            index++;
          }
      }
  }
  return inserted;
  
}
bool HashTable::quadraticProbingInsert(Person person){
    
    unsigned int index = m_hash(person.key()) % m_capacity;
    bool inserted = false;
    while(!inserted){
        if(m_size == m_capacity){
            cout<<"TABLE IS FULL"<<endl;
            return false;
        }
        else if(m_table[index] == person){
            cout<<"PERSON ALREADY IN HASH TABLE"<<endl;
            return false;
        }
        else if(m_table[index] == EMPTY){
            m_table[index] = person;
            m_size++;
            //cout<<"HELLO"<<endl;
            inserted = true;
        }
        else{
            unsigned int counter = 0;
            while(counter < (m_capacity - 1) && !inserted){
                index = (m_hash(person.key()) + (counter * counter)) % m_capacity;
                if(m_table[index] == EMPTY){
                    m_table[index] = person;
                    m_size++;
                    
                    inserted = true;
                }
                else{
                    
                    counter++;
                }
            }

        }
    }
    return inserted;


}
bool HashTable::remove(Person person){
   
    bool removeType;
    if(m_currentProb == LINEAR){
        
        removeType = linearProbingRemove(person);
        if(removeType && deletedRatio() > 0.25 ){
            setProbingPolicy(QUADRATIC);
        }
    }
    else{
        
        removeType = quadraticProbingRemove(person);
        if(removeType && deletedRatio() > 0.25){
            setProbingPolicy(LINEAR);
            
        }
    }

   return removeType;
}

bool HashTable::linearProbingRemove(Person person){
    unsigned int index = m_hash(person.key()) % m_capacity;
    bool removed = false;
    while(!removed){

        if(m_size == 0){
            cout<<"CANT REMOVE FROM EMPTY TABLE"<<endl;
            return false;
        }
        else if(m_table[index] == person){
            m_table[index] = DELETED;
            m_numDeleted++;
            removed = true;
        }
        else{

            if(index >= m_capacity - 1){
                index = 0;
            }
            else{
                index++;
            }
        }
    }
    return removed;

}
bool HashTable::quadraticProbingRemove(Person person){
    
    unsigned int index = (m_hash(person.key())) % m_capacity;
    bool removed = false;
    while(!removed){
        if(m_size == 0){
            cout<<"CANT REMOVE FROM EMPTY TABLE"<<endl;
            return false;
        }
        else if(m_table[index] == person){
            m_table[index] = DELETED;
            m_numDeleted++;
            //cout<<index<<endl;
            removed = true;

        }
        else{
            unsigned int counter = 0;
            while(counter < m_capacity && !removed){
                
                index = (m_hash(person.key()) + (counter * counter)) % m_capacity;
                
                if(m_table[index] == person){
                    //cout<<person.serial()<<" "<<m_table[index].serial()<<endl;
                    m_table[index] = DELETED;
                    m_numDeleted++;
                    
                    //cout<<index<< " "<<counter<<endl;
                    removed = true;

                }
                else{
                    
                    
                    counter = (counter + 1) % m_capacity;
                }


            }
        }
    }
    
    
    return removed;
}

void HashTable::setProbingPolicy(probing prob){
    
    m_currentProb = prob;
    reHash(prob);
    //cout<<"rehashing "<<m_currentProb<<endl;
}

float HashTable::lambda() const {

    if(m_capacity > 0){
        return (float) m_size / (float) m_capacity;
    }
    return 0;
        
}

float HashTable::deletedRatio() const {

    if(m_size > 0){
        return (float) m_numDeleted / m_size;
    }
    return 0;
    
    
}

void HashTable::dump() const {
  for (unsigned int i = 0; i < m_capacity; i++) {
    cout << "[" << i << "] : " << m_table[i] << endl;
  }
}

bool HashTable::isPrime(int number){
    // If number is prime this function returns true
    // otherwise it returns false
    bool result = true;
    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            result = false;
            break;
        }
    }
    return result;
}

int HashTable::findNextPrime(int current){
    //we won't go beyond MAXPRIME
    //the smallest prime would be next after MINPRIME
    if (current < MINPRIME) current = MINPRIME;
    for (int i=current; i<MAXPRIME; i++) { 
        for (int j=2; j*j<=i; j++) {
            if (i % j == 0) 
                break;
            else if (j+1 > sqrt(i) && i != current) {
                return i;
            }
        }
    }
    //if a user tries to go over MAXPRIME
    return MAXPRIME;
}
