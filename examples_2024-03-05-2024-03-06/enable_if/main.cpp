#include "traits.hpp"

int main(int argc, char const *argv[]) {
    Foo f;
    call_bar(f);
    int x = 10;
    // call_bar(x); // will not work as x provides no 'bar' method
    return 0;
}
