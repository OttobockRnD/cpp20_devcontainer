#include <concepts>
#include <iostream>
#include <memory>

template <typename T>
concept FooBarConcept = requires(T t) {
    { t.bar() };
};

template <typename T>
concept FooBarConcept2 = requires(T t, int v) {
    { t.baz() };
    { t.f(v) };
};

template <typename T>
concept FooBarConcept3 = requires(T t, int v) {
    { t.baz() } -> std::integral;
    { t.f(v) };
};

template<FooBarConcept3 T>
void handle(T t) {
    t.bar();
    t.baz();
    t.f(42);
}

template<typename T>
requires FooBarConcept3<T> && FooBarConcept2<T>
void handle2(T t) {
    t.bar();
    t.baz();
    t.f(42);
}

class Foo {
    public:
        void bar() {
            std::cout << "Foo bar" << std::endl;
        }
        double baz() {
            return 42.3;
        }
        void f(int x) {
            std::cout << "Foo f " << x << std::endl;
        }
};

class Bar {
    public:
        void bar() {
            std::cout << "Bar bar" << std::endl;
        }
        int baz() {
            return 42;
        }
        void f(std::string x) {
            std::cout << "Bar f " << x << std::endl;
        }
};

int main(int argc, char const *argv[]) {
    Foo f;
    Bar b;
    // handle2(f);
    handle(f);
    // std::shared_ptr<int> p = std::make_shared<int>(42);
    // handle2(f);
    return 0;
}
