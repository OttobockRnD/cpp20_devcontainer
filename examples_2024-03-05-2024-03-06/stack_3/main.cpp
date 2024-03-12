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

void test(Stack s) {
    s.push(1);

}

Stack createAndFill(int size) {
    Stack s {size};
    for (int i = 0; i < size; i++) {
        s.push(i);
    }
    return s;
}

int main(int argc, char const *argv[]) {    
    Stack s = createAndFill(3);
    while (!s.isEmpty()) {
        cout << s.pop() << endl;
    }
    return 0;
}
