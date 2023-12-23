#ifndef TASK_1_CIRCULARBUFFER_H
#define TASK_1_CIRCULARBUFFER_H

#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;
typedef char Type;

class CircularBuffer {
private:
    Type* buffer;
    int maxSize;        //capacity of buffer
    int elemCount;      //size of buffer
    int head;           //index of the 1st element
    int tail;           //index of the last element

public:
//Constructor
    CircularBuffer();
//Destructor
    ~CircularBuffer();
//Create new buffer from existing buffer (The copy constructor).
    CircularBuffer(const CircularBuffer& cb);
//Create an empty buffer with the specified capacity.
    explicit CircularBuffer(int capacity);
//Create a full buffer with the specified capacity and filled with the copies of item.
    CircularBuffer(int capacity, const Type& elem);
//Get the element at the index position. Does not check the correctness of the index.
    Type& operator[](int i);
    const Type& operator[](int i) const;
//Get the element at the index position. Methods throw an exception in case of wrong index.
    Type& at(int i);
    const Type& at(int i) const;
//Get the first element.
    Type& front();
    const Type& front() const;
//Get the last element.
    Type& back();
    const Type& back() const;
//Linearize buffer into a continuous array. Shift the ring buffer
//so that its first element moves to the beginning of the allocated memory.
    Type* linearize();
//Check if the buffer is linearized.
    bool is_linearized() const;
//Shift the buffer so that an element with the new_begin index appears at the zero index.
    void rotate(int new_begin);
//Get an unlinearized array from the buffer
    Type* array();
    const Type* array() const;
//The number of elements stored in the buffer.
    int size() const;
//Return true, if size() == 0.
    bool empty() const;
//Return true, if size() == capacity().
    bool full() const;
//The number of free cells.
    int reserve() const;
//The buffer capacity.
    int capacity() const;
//Change the buffer capacity.
    void set_capacity(int new_capacity);
//Change the buffer size.
//In case of buffer expansion, the new cells are filled with the item element.
    void resize(int new_size, const Type& item = Type());
//Assignment operator. Make this buffer to become a copy of the specified buffer.
    CircularBuffer& operator=(const CircularBuffer& cb);
//Swap the contents of two buffers.
    void swap(CircularBuffer& cb);
//Insert a new element at the end of the buffer.
    void push_back(const Type& item = Type());
//Insert a new element at the beginning of the circular_buffer.
    void push_front(const Type& item = Type());
//Remove the last element from the circular_buffer.
    Type& pop_back();
//Remove the last element from the circular_buffer.
    Type& pop_front();
//Insert an element at the specified position.
    void insert(int pos, const Type item = Type());
//Erase elements from the buffer in the range [first, last).
    void erase(int first, int last);
//Clear the buffer.
    void clear();
};
bool operator==(const CircularBuffer& a, const CircularBuffer& b);
bool operator!=(const CircularBuffer& a, const CircularBuffer& b);

#endif //TASK_1_CIRCULARBUFFER_H