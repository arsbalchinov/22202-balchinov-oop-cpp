#include "CircularBuffer.h"

using namespace std;

int main() {
    // Create a circular buffer with a capacity for 3 doubles.
    CircularBuffer<double> cb(3);
    // Insert some elements into the buffer.
    cb.push_back(1.1);
    cb.push_back(2.2);
    cb.push_back(3.3);
    double a = cb[0];  // a == 1.1
    double b = cb[1];  // b == 2.2
    double c = cb[2];  // c == 3.3
    cout<< a <<" "<< b <<" "<< c <<endl;
    // The buffer is full now, pushing subsequent elements will overwrite the front-most elements.
    cb.push_back(4.4);  // Overwrite 1 with 4.
    cb.push_back(5.5);  // Overwrite 2 with 5.
    // The buffer now contains 3.3, 4.4 and 5.5.
    a = cb[0];  // a == 3.3
    b = cb[1];  // b == 4.4
    c = cb[2];  // c == 5.5
    cout<< a <<" "<< b <<" "<< c <<endl;
    // Elements can be popped from either the front or the back.
    cb.pop_back();  // 5.5 is removed.
    cb.pop_front(); // 3.3 is removed.
    double d = cb[0];  // d == 4.4
    cout<< d <<endl;
    return 0;
}