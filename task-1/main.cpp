#include "CircularBuffer.h"

using namespace std;

int main() {
    // Create a circular buffer with a capacity for 3 chars.
    CircularBuffer cb(3);
    // Insert some elements into the buffer.
    cb.push_back(49);
    cb.push_back(50);
    cb.push_back(51);
    char a = cb[0];  // a == 1
    char b = cb[1];  // b == 2
    char c = cb[2];  // c == 3
    cout<< a <<" "<< b <<" "<< c <<endl;
    // The buffer is full now, pushing subsequent elements will overwrite the front-most elements.
    cb.push_back(52);  // Overwrite 1 with 4.
    cb.push_back(53);  // Overwrite 2 with 5.
    // The buffer now contains 3, 4 and 5.
    a = cb[0];  // a == 3
    b = cb[1];  // b == 4
    c = cb[2];  // c == 5
    cout<< a <<" "<< b <<" "<< c <<endl;
    // Elements can be popped from either the front or the back.
    cb.pop_back();  // 5 is removed.
    cb.pop_front(); // 3 is removed.
    char d = cb[0];  // d == 4
    cout<< d <<endl;
    return 0;
}