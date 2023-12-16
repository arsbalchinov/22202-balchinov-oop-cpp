#include "CircularBuffer.h"
typedef char Type;

//Constructor
    CircularBuffer::CircularBuffer() {
        buffer = nullptr;
        maxSize = 0;
        elemCount = 0;
        head = 0;
        tail = 0;
    }
//Destructor
    CircularBuffer::~CircularBuffer() {
        delete[] buffer;
    }
//Create new buffer from existing buffer (The copy constructor).
    CircularBuffer::CircularBuffer(const CircularBuffer& cb) {
        maxSize = cb.maxSize;
        elemCount = cb.elemCount;
        head = cb.head;
        tail = cb.tail;
        buffer = new Type[maxSize];
        for (int i = 0; i < maxSize; i++) {
            buffer[i] = cb[i];
        }
    }
//Create an empty buffer with the specified capacity.
    CircularBuffer::CircularBuffer(int capacity) {
        maxSize = capacity;
        elemCount = 0;
        head = 0;
        tail = 0;
        buffer = new Type[maxSize];
    }
//Create a full buffer with the specified capacity and filled with the copies of item.
    CircularBuffer::CircularBuffer(int capacity, const Type& elem) {
        maxSize = capacity;
        elemCount = capacity;
        head = 0;
        tail = max(0, capacity - 1);
        buffer = new Type[maxSize];
        for (int i = 0; i < maxSize; i++) {
            buffer[i] = elem;
        }
    }
//Get the element at the index position. Does not check the correctness of the index.
    Type& CircularBuffer::operator[](int i) {
        int index = (head + i) % maxSize;
        return buffer[index];
    }
    const Type& CircularBuffer::operator[](int i) const {
        int index = (head + i) % maxSize;
        return buffer[index];
    }
//Get the element at the index position. Methods throw an exception in case of wrong index.
    Type& CircularBuffer::at(int i) {
        if (i < 0 || i >= elemCount) {
            throw out_of_range("Wrong index");
        }
        int index = (head + i) % maxSize;
        return buffer[index];
    }
    const Type& CircularBuffer::at(int i) const {
        if (i < 0 || i >= elemCount) {
            throw out_of_range("Wrong index");
        }
        int index = (head + i) % maxSize;
        return buffer[index];
    }
//Get the first element.
    Type& CircularBuffer::front() {
        if (elemCount == 0) {
            throw out_of_range("Buffer is empty");
        }
        return buffer[head];
    }
    const Type& CircularBuffer::front() const {
        if (elemCount == 0) {
            throw out_of_range("Buffer is empty");
        }
        return buffer[head];
    }
//Get the last element.
    Type& CircularBuffer::back() {
        if (elemCount == 0) {
            throw out_of_range("Buffer is empty");
        }
        return buffer[tail];
    }
    const Type& CircularBuffer::back() const {
        if (elemCount == 0) {
            throw out_of_range("Buffer is empty");
        }
        return buffer[tail];
    }
//Linearize buffer into a continuous array. Shift the ring buffer
//so that its first element moves to the beginning of the allocated memory.
    Type* CircularBuffer::linearize() {
        if (elemCount == 0) {
            return nullptr;
        }
        std::rotate(buffer, buffer + head, buffer + maxSize);
        head = 0;
        tail = elemCount - 1;
        return buffer;
    }
//Check if the buffer is linearized.
    bool CircularBuffer::is_linearized() const {
        return head == 0;
    }
//Shift the buffer so that an element with the new_begin index appears at the zero index.
    void CircularBuffer::rotate(int new_begin) {
        if (new_begin < 0 || new_begin >= elemCount) {
            throw out_of_range("Wrong new begin");
        }
        int index = (head + new_begin) % maxSize;
        std::rotate(buffer, buffer + index, buffer + maxSize);
    }
//Get an unlinearized array from the buffer
    Type* CircularBuffer::array() {
        return buffer;
    }
//The number of elements stored in the buffer.
    int CircularBuffer::size() const {
        return elemCount;
    }
//Return true, if size() == 0.
    bool CircularBuffer::empty() const {
        return elemCount == 0;
    }
//Return true, if size() == capacity().
    bool CircularBuffer::full() const {
        return elemCount == maxSize;
    }
//The number of free cells.
    int CircularBuffer::reserve() const {
        return maxSize - elemCount;
    }
//The buffer capacity.
    int CircularBuffer::capacity() const {
        return maxSize;
    }
//Change the buffer capacity.
    void CircularBuffer::set_capacity(int new_capacity) {
        linearize();
        Type* new_buffer = new Type[new_capacity];
        for (int i = 0; i < min(elemCount, new_capacity); i++) {
            new_buffer[i] = buffer[i];
        }
        maxSize = new_capacity;
        elemCount = min(elemCount, new_capacity);
        tail = max(0, elemCount - 1);

        delete[] buffer;
        buffer = new_buffer;
    }
//Change the buffer size.
//In case of buffer expansion, the new cells are filled with the item element.
    void CircularBuffer::resize(int new_size, const Type& item) {
        if (new_size == elemCount) {
            return;
        }
        if (new_size > maxSize) {
            set_capacity(new_size);
        }
        if (new_size > elemCount) {
            int new_cells = new_size - elemCount;
            for (int i = 0; i < new_cells; i++) {
                push_back(item);
            }
        }
        else {
            erase(new_size,elemCount);
        }
    }
//Assignment operator. Make this buffer a copy of the specified buffer.
    CircularBuffer& CircularBuffer::operator=(const CircularBuffer& cb) {
        if (&cb != this) {
            maxSize = cb.maxSize;
            elemCount = cb.elemCount;
            head = cb.head;
            tail = cb.tail;
            Type* oldBuffer = buffer;
            buffer = new Type[maxSize];
            for (int i = 0; i < elemCount; i++) {
                buffer[i] = cb[i];
            }
            delete[] oldBuffer;
        }
        return *this;
    }
//Swap the contents of two buffers.
    void CircularBuffer::swap(CircularBuffer& cb) {
        std::swap(buffer, cb.buffer);
        std::swap(maxSize, cb.maxSize);
        std::swap(elemCount, cb.elemCount);
        std::swap(head, cb.head);
        std::swap(tail, cb.tail);
    }
//Insert a new element at the end of the buffer.
    void CircularBuffer::push_back(const Type& item) {
        if (maxSize == 0) {
            throw out_of_range("Buffer has zero capacity");
        }
        tail = (elemCount == 0) ? tail : (tail + 1) % maxSize;
        buffer[tail] = item;
        head = (elemCount == maxSize) ? (head + 1) % maxSize : head;
        elemCount = (elemCount == maxSize) ? elemCount : elemCount + 1;
    }
//Insert a new element at the beginning of the buffer.
    void CircularBuffer::push_front(const Type& item) {
        if (maxSize == 0) {
            throw out_of_range("Buffer has zero capacity");
        }
        head = (elemCount == 0) ? head : (head - 1 + maxSize) % maxSize;
        buffer[head] = item;
        tail = (elemCount == maxSize) ? (tail - 1 + maxSize) % maxSize : tail;
        elemCount = (elemCount == maxSize) ? elemCount : elemCount + 1;
    }
//Remove the last element from the buffer.
    Type& CircularBuffer::pop_back() {
        Type& backElement = back();
        elemCount--;
        if (elemCount == 0) {
            tail = head;
        }
        else {
            tail = (tail - 1 + maxSize) % maxSize;
        }
        return backElement;
    }
//Remove the last element from the buffer.
    Type& CircularBuffer::pop_front() {
        Type& frontElement = front();
        elemCount--;
        if (elemCount == 0) {
            head = tail;
        }
        else {
            head = (head + 1) % maxSize;
        }
        return frontElement;
    }
//Insert an element at the specified position.
    void CircularBuffer::insert(int pos, const Type item) {
        if (maxSize == 0) {
            throw out_of_range("Buffer has zero capacity");
        }
        if (pos < 0 || pos > elemCount) {
            throw out_of_range("Wrong insert position");
        }
        int oldHead = head;
        push_back();
        for (int i = elemCount - 1; i > pos; i--) {
            buffer[i] = buffer[i - 1]; // pos + 1 = pos
        }
        int index = (oldHead + pos) % maxSize;
        buffer[index] = item;
    }
//Erase elements from the buffer in the range [first, last).
    void CircularBuffer::erase(int first, int last) {
        if (first < 0 || first > elemCount || last < 0 || last > elemCount) {
            throw out_of_range("Wrong index");
        }
        if (first == last) {
            return;
        }
        if (first > last) {
            throw invalid_argument("Index of the last element must be greater than index of the first");
        }
        for (int i = last; i < elemCount; i++) {
            int shift = i - last;
            buffer[first + shift] = buffer[i];
        }
        int deleted = last - first;
        elemCount -= deleted;
        if (elemCount == 0) {
            tail = head;
        }
        else {
            tail = (tail - deleted + maxSize) % maxSize;
        }
    }
//Clear the buffer.
    void CircularBuffer::clear() {
        elemCount = 0;
        tail = head;
    }
//Check if the buffers are equal.
bool operator==(const CircularBuffer& a, const CircularBuffer& b) {
    if (a.capacity() != b.capacity() || a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}
bool operator!=(const CircularBuffer& a, const CircularBuffer& b) {
    if (a.capacity() != b.capacity() || a.size() != b.size()) {
        return true;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return true;
        }
    }
    return false;
}