#include "bufferlist.h"

BufferList::BufferList(int minBufCapacity){
    // **************************************
    // Implement the alternative constructor
    // **************************************
    if(minBufCapacity < 1){
        minBufCapacity = DEFAULT_MIN_CAPACITY;
    }
    m_minBufCapacity = minBufCapacity;
    m_cursor = new Buffer(m_minBufCapacity);
    m_listSize = 1;
    m_cursor -> m_next = m_cursor;
   
  
}
BufferList::~BufferList(){
    clear();
}

void BufferList::clear(){
    // *****************************
    // Implement clear() function
    // *****************************
    for(int i = 0; i < m_listSize;i++){
        Buffer* temp = m_cursor;    
        m_cursor = m_cursor->m_next;
        delete temp;
    }
    //delete m_cursor->m_next;
    //delete m_cursor;
    //m_cursor = nullptr;
    //m_cursor ->m_next = nullptr;
    m_listSize = 0;
    m_minBufCapacity = 0;
}


void BufferList::enqueue(const int& data) {
    // ****************************************************************************
    // Implement enqueue(...) function
    // we always insert at the back, that would be the cursor
    // if the current cursor is full we create a new node as cursor then we insert
    // ****************************************************************************
    
    try{
        
        m_cursor->enqueue(data);  
                                                

    }
    catch(overflow_error & e){
        Buffer* head = m_cursor -> m_next;
        
        //cout<<e.what()<<endl;
        if(m_minBufCapacity <  head->capacity() * MAX_FACTOR){
            m_minBufCapacity *= INCREASE_FACTOR;
        }
        else{
            m_minBufCapacity = head->capacity();
        }
        //cout<<"SIZE: "<<m_minBufCapacity<<endl;
        Buffer* new_buffer = new Buffer(m_minBufCapacity);
        new_buffer->enqueue(data);
        new_buffer -> m_next = m_cursor -> m_next;
        m_cursor -> m_next = new_buffer;
        m_cursor = m_cursor -> m_next;
        m_listSize++;
        
        
    }
    
    
}

int BufferList::dequeue() {
    // *****************************
    // Implement dequeue() function
    // *****************************
    
   Buffer* head = m_cursor -> m_next;
   try{

       head->dequeue();
       
   }
   catch(underflow_error &u){
        
        if(m_cursor == head){
            //m_cursor = nullptr;
            
            m_cursor->clear();
            head->clear();
            throw underflow_error("BufferList is Empty");      
        }            
        else{
            m_cursor->m_next = head->m_next;
            
        }
        delete head;
        m_listSize--;

   }
   return 0;
}

BufferList::BufferList(const BufferList & rhs){
    // *******************************
    // Implement the copy constructor
    // *******************************
    
    this->m_listSize = rhs.m_listSize;
    this->m_minBufCapacity = rhs.m_minBufCapacity;
    //this->m_cursor = new Buffer(*rhs.m_cursor);
    //this->m_cursor->m_next = new Buffer(*rhs.m_cursor->m_next);
    
    Buffer* temp = rhs.m_cursor;
    for(int i = 0; i < m_listSize;i++){
        //Buffer* new_buffer = new Buffer(*temp);

        m_cursor = new Buffer(*temp);
       
        temp = temp ->m_next;
        m_cursor = m_cursor->m_next;
    }
    
    this->m_cursor = temp;
    
    
}

const BufferList & BufferList::operator=(const BufferList & rhs){
    // ******************************
    // Implement assignment operator
    // ******************************
    
    return *this;
}

void BufferList::dump(){
    
    Buffer* temp = m_cursor->m_next;
    for(int i=0;i<m_listSize;i++){
        temp->dump();
        temp = temp->m_next;
        cout << endl;
    }
    cout << endl;
    
}