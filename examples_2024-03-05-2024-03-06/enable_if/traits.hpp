#include <type_traits>

class Foo {
    public:
        void bar() {}
};

template<class T>
using is_foo_type = std::is_same<Foo, T>;

template<class T, typename std::enable_if<is_foo_type<T>::value>::type* = nullptr>
void call_bar(T t) {
    t.bar();
}