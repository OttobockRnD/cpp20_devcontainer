#include <iostream>
#include <vector>
#include "stack.hpp"


using namespace std;

class Foo {

};

Foo bar() {
    Foo f;
    return f;
}

int main(int argc, char const *argv[]) {    
    Stack s = createDefaultStack<double>();
    s.push(22.3);
    s.push(10);
    s.push(10);
    while (!s.isEmpty()) {
        cout << s.pop() << endl;
    }

    return 0;
}
