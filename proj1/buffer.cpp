#include "buffer.h"

Buffer::Buffer(int capacity)
{
    // **************************************
    // Implement the alternative constructor
    // No need to set m_next to nullptr,
    // it will be handled by linked list,
    // because it is used by linked list
    // **************************************
    m_count = m_end = m_start = 0;
    m_next = nullptr;
    if(capacity < 1){
        m_capacity = 0;
        m_buffer = nullptr;
    }
    else{
        m_capacity =  capacity;
        m_buffer = new int[m_capacity]{0};
    }
    
    
    
   
    
   
    
}

void Buffer::clear()
{
    // ***********************************
    // Implement clear() function
    // No need to set m_next to nullptr,
    // it will be handled by linked list,
    // because it is used by linked list
    // ***********************************

    if (m_capacity > 0)
    {
        delete[] m_buffer;
    }
    
   
    m_buffer = nullptr;
    m_capacity = 0;
    m_count = 0;
    m_start = 0;
    m_end = 0;
    m_next = nullptr;
}

Buffer::~Buffer()
{
    clear();
}

int Buffer::count() { return m_count; }

int Buffer::capacity() { return m_capacity; }

bool Buffer::full()
{
    // **************************
    // Implement full() function
    // **************************
    return m_count == m_capacity;
}

bool Buffer::empty()
{
    // **************************
    // Implement empty() function
    // **************************
    return m_count == 0;
}
void Buffer::enqueue(int data)
{
    // ********************************
    // Implement enqueue(...) function
    // ********************************
    /* code */
    if (full())
    {
        throw overflow_error("Buffer is full");
    }

    else if (m_start == m_end)
    {
        m_buffer[m_start] = data;
        m_count++;
        m_end++;
    }
    else if (m_start != 0 && m_end == m_capacity - 1)
    {
        m_end = 0;
        m_buffer[m_end] = data;
        m_count++;
    }
    else
    {
        m_buffer[m_end] = data;
        m_count++;
        m_end++;
    }
}

int Buffer::dequeue()
{
    // *****************************
    // Implement dequeue() function
    // *****************************
    int oldStart = m_start;
    if (empty())
    {
        throw underflow_error("Buffer is empty");
    }
    else
    {

        m_start = (m_start + 1) % m_capacity;
        m_count--;
    }
    return m_buffer[oldStart];
}

Buffer::Buffer(const Buffer &rhs)
{
    // *******************************
    // Implement the copy constructor
    // *******************************

    m_capacity = rhs.m_capacity;
    m_count = rhs.m_count;
    m_start = rhs.m_start;
    m_end = rhs.m_end;
  
    if (m_capacity > 0)
    {
        m_buffer = new int[m_capacity];
    }
    for (int i = 0; i < m_capacity; i++)
    {
        m_buffer[i] = rhs.m_buffer[i];
    }
}

const Buffer &Buffer::operator=(const Buffer &rhs)
{
    // ******************************
    // Implement assignment operator
    // ******************************
    if (this != &rhs)
    {
        clear();
        m_capacity = rhs.m_capacity;
        m_count = rhs.m_count;
        m_end = rhs.m_end;
        m_start = rhs.m_start;
        m_next = rhs.m_next;
        m_buffer = new int[rhs.m_capacity];
        for (int i = 0; i < rhs.m_capacity - 1; i++)
        {
            this->m_buffer[i] = rhs.m_buffer[i];
        }
    }
    return *this;
}

void Buffer::dump()
{
    int start = m_start;
    //int end = m_end;
    int counter = 0;
    cout << "Buffer size: " << m_capacity << " : ";
    if (!empty())
    {
        while (counter < m_count)
        {
            cout << m_buffer[start] << "[" << start << "]"
                 << " ";
            start = (start + 1) % m_capacity;
            counter++;
        }
        cout << endl;
    }
    else
        cout << "Buffer is empty!" << endl;
}