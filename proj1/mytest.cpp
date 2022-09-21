#include "bufferlist.h"

class Tester
{
public:
    bool BufferEnqueueDequeue(Buffer &buffer, int dataCount);
    bool BufferEnqueueFull(int size);
    bool BufferCopyConstructor(const Buffer& buffer);
    bool BufferAssignmentOperator(const Buffer& buffer);
    //bool BufferCopyConstructor(const Buffer &buffer);
    //void BufListEnqueuePerformance(int numTrials, int N);
};

int main()
{
    Tester tester;
    int bufferSize = 1000;
    Buffer buffer(bufferSize);
    BufferList bufferList(4);
    /**
    {
        //testing insertion/removal for no data item
        cout << "\nTest case: Buffer class: Inserting/removing no data items:\n";
        if (tester.BufferEnqueueDequeue(buffer, 0))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing insertion/removal for 1 data item
        cout << "\nTest case: Buffer class: Inserting/removing 1 data item:\n";
        if (tester.BufferEnqueueDequeue(buffer, 1))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    
    
    {
      
        //testing insertion/removal for half data size
        cout << "\nTest case: Buffer class: Inserting/removing half data size:\n";
        if (tester.BufferEnqueueDequeue(buffer, bufferSize/2))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
        
    }
  
   

    {
     
        //testing insertion/removal for full data size
        cout << "\nTest case: Buffer class: Inserting/removing full data size:\n";
        if (tester.BufferEnqueueDequeue(buffer, bufferSize))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    
    
    {
        //testing insertion in a full buffer
        cout << "\nTest case: Buffer class: Throwing exception while inserting in full buffer:\n";
        if (tester.BufferEnqueueFull(1000))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    
    
    {
        //testing Buffer class copy constructor with buffer size of zero
        cout << "\nTest case: Buffer class: Copy constructor, zero buffer size:\n";
        Buffer buffer(0);
        if (tester.BufferCopyConstructor(buffer))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n"; 
       
    }
    
    {
        //testing Buffer class copy constructor with buffer size less than zero
        cout << "\nTest case: Buffer class: Copy constructor, negative buffer size:\n";
        Buffer buffer(-10);
        if (tester.BufferCopyConstructor(buffer))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n"; 
    }
    
    {
        //testing Buffer class copy constructor with buffer size of one
        cout << "\nTest case: Buffer class: Copy constructor, 1 buffer size:\n";
        Buffer buffer(1);
        if (tester.BufferCopyConstructor(buffer))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n"; 
    }
    
    
    {
        //testing Buffer class copy constructor with buffer size greater than zero
        cout << "\nTest case: Buffer class: Copy constructor, huge buffer size:\n";
        Buffer buffer(1000);
        if (tester.BufferCopyConstructor(buffer))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n"; 
    }
    
    {
        //testing Buffer class assignment operator with negative buffer size
        cout << "\nTest case: Buffer class: Assignment operator, negative buffer size:\n";
        Buffer buffer(-10);
        if(tester.BufferAssignmentOperator(buffer))
            cout<<"\tTest passed!\n";
        else
            cout << "\tTest failed!\n"; 
    }
    
    {
        //testing Buffer class assignment operator with zero buffer size
        cout << "\nTest case: Buffer class: Assignment operator, zero buffer size:\n";
        Buffer buffer(0);
        if(tester.BufferAssignmentOperator(buffer))
            cout<<"\tTest passed!\n";
        else
            cout << "\tTest failed!\n"; 
    }
    
    {
        //testing Buffer class assignment operator with one buffer size
        cout << "\nTest case: Buffer class: Assignment operator, one buffer size:\n";
        Buffer buffer(1);
        if(tester.BufferAssignmentOperator(buffer))
            cout<<"\tTest passed!\n";
        else
            cout << "\tTest failed!\n"; 
    }
    
    {
        //testing Buffer class assignment operator with negative buffer size
        cout << "\nTest case: Buffer class: Assignment operator, negative buffer size:\n";
        Buffer buffer(1000);
        if(tester.BufferAssignmentOperator(buffer))
            cout<<"\tTest passed!\n";
        else
            cout << "\tTest failed!\n"; 
    }
    **/
    
    for(int i = 0; i < 124;i++){
        bufferList.enqueue(i);
    }
    BufferList copy(bufferList);
    cout<<"Copy"<<endl;
    copy.dump();
    
    
    return 0;
}

bool Tester::BufferEnqueueDequeue(Buffer &buffer, int dataCount)
{
    Buffer p1(buffer);
    for(int i = 0; i < dataCount; i++){
        p1.enqueue(i);
    }
    for(int i = 0; i < dataCount;i++){
        if(p1.m_buffer[p1.m_start] != p1.dequeue()){
            return false;
        }
    }
    return true;
}
bool Tester::BufferEnqueueFull(int size){
    Buffer aBuffer(size);
    for (int i=0;i<size;i++)
        aBuffer.enqueue(i);
    try{
        //trying to insert in a full buffer
        aBuffer.enqueue(size+1);
    }
    catch(overflow_error &e){
        //the exception that we expect
        return true;
    }
    catch(...){
        //any other exception, this case is not acceptable
        return false;
    }
    //no exception thrown, this case is not acceptable
    return false;
}
bool Tester::BufferCopyConstructor(const Buffer& buffer){
    Buffer copy(buffer);
    //case of empty buffer object
    if(buffer.m_capacity == 0 && copy.m_capacity == 0) return true;
    //the case that sizes are the same and the table pointers are not the same
    else if(buffer.m_capacity == copy.m_capacity && buffer.m_buffer != copy.m_buffer){

        if(buffer.m_buffer != copy.m_buffer){
            for(int i = 0; i < buffer.m_capacity;i++){
                if(buffer.m_buffer[i] != copy.m_buffer[i]){
                    
                    return false;
                }
            }
            
        }
        return true;
        
    }
    else return false;
    


}
bool Tester::BufferAssignmentOperator(const Buffer& buffer){
    Buffer temp = buffer;
    temp = temp;
    //Same table size but different buffer pointers
    if((temp.m_capacity == buffer.m_capacity) || (temp.m_buffer != buffer.m_buffer)){
        
        for(int i = 0; i < temp.m_capacity;i++){

            if(temp.m_buffer[i] != buffer.m_buffer[i]){
                return false;
            }
        }
        return true;
    }
    else return false;
}
