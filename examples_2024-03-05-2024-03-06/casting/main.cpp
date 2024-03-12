#include <iostream>

class Base {
    public: virtual int foo() = 0;
};

class Derived1 : public Base {
    public: int foo() override { return 1; }
};

class Derived2 : public Base {
    public: int foo() override { return 2;}
};

class Foo {
    public:
        void bar() {
            std::cout << "Foo bar" << std::endl;
        }

        operator int() const { return 42; }
};

void showDynamicCast() {
    Base* b1 = new Derived1();
    Derived1* d = dynamic_cast<Derived1*>(b1);
    if (d) {
        std::cout << d->foo() << std::endl;
    }
    Derived2* e = dynamic_cast<Derived2*>(b1);
    if (e) {
         std::cout << e->foo() << std::endl;
    }
    Base* b2 = dynamic_cast<Base*>(d);
    if (b2) {
        std::cout << b2->foo() << std::endl;
    }
}

#include <iostream>

struct Packet {
    uint16_t crc;
    uint8_t version;
};

void receiveData(uint8_t* raw, size_t size) {
}

int main() {
    uint8_t data[1024];
    receiveData(buffer, 1024);
    Packet* packet = reinterpret_cast<Packet*>(buffer);
    return 0;
}

int main(int argc, char const *argv[]) {
    // float f = 3.14;
    // int a = static_cast<int>(f);
    // std::cout << a << std::endl;
    // int b = static_cast<int>(Foo{});
    // std::cout << b << std::endl;

    //--------------------------------------------------------------------------------
    // showDynamicCast();
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    int x = 42;
    const int& crefX = x;
    int& refX = const_cast<int&>(crefX);
    refX = 10;
    std::cout << x << std::endl;

    const int y = 10;
    int& yRef = const_cast<int&>(y);
    yRef = 20;
    std::cout << yRef << std::endl;
    //--------------------------------------------------------------------------------

    return 0;
}
