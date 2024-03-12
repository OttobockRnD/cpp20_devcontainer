#include <type_traits>
#include <memory>
#include <iostream>

using namespace std;

template<typename T>
enable_if_t<is_function_v<T>> foo(T v);

template <typename T>
void foo(T x) {
    x();
}

auto maximum(std::copyable auto a, std::copyable auto b) {
    return a > b ? a : b;
}

void foo(const char* v) {
    cout << "is string " << v << endl;
}

int main(int argc, char const *argv[]) {
    shared_ptr<int> pi1 = make_shared<int>(47);
    shared_ptr<int> pi2 = make_shared<int>(11);
    // unique_ptr<int> pi1 = make_unique<int>(47);
    // unique_ptr<int> pi2 = make_unique<int>(11);
    cout << maximum(pi1, pi2) << endl;

    foo("test");
    foo([]() { cout << "is lambda" << endl; });
    return 0;
}
