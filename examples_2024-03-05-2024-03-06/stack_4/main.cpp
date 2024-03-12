#include <iostream>
#include <array>
#include "stack.hpp"


using namespace std;

Stack<double> createAndFill(int size) {
    Stack<double> s {size};
    for (int i = 0; i < size; i++) {
        s.push(i);
    }
    return s;
}

int main(int argc, char const *argv[]) {    
    Stack<double> s {3};
    s.push(3.14);
    s.push(2.71);
    while(!s.isEmpty()) {
        cout << s.pop() << endl;
    }

    return 0;
}
