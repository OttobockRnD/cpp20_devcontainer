#include <iostream>
#include <optional>
#include <variant>
#include <stdexcept>
#include <memory>

using namespace std;

// int divide(int a, int b) {
//     return a/b;
// }

// optional<int> divide(int a, int b) {
//     if (b == 0) {
//         return nullopt;
//     }
//     return a / b;
// }

// bool divide(int a, int b, int& result) {
//     if (b == 0) {
//         return false;
//     }
//     result = a / b;
//     return true;
// }

// variant<int, string> divide(int a, int b) {
//     if (b == 0) {
//         return "Error: Division by zero";
//     }
//     return a / b;
// }

class Bar {
    public:
        ~Bar() { cout << "Bar destructor" << endl;}
};

class FooBarException: public std::exception {
    private:
        std::string _message;
    public:
        FooBarException(std::string message) : _message(message) {};
        const char* what() const noexcept override {
            return _message.c_str();
        }
};

class Foo {
    unique_ptr<Bar> _pData;    
    public:
        Foo() : _pData(make_unique<Bar>()) {
            throw FooBarException("Foo constructor failed");
        }
        ~Foo() { cout << "Foo destructor" << endl;}
 };

 


// unique_ptr<Foo> bar(int x) {
//     unique_ptr<Foo> f = make_unique<Foo>();
//     if (x == 0) {
//         throw invalid_argument("x cannot be zero");
//     }
//     return f;
// }

void foo() {
    try {
        Foo f;
    } catch (const FooBarException& e) {
        cerr << "before rethrow" << endl;
        throw;
    }
}

int main(int argc, char const *argv[]) {
    try {
        foo();
    } catch (const FooBarException& e) {
        cerr << e.what() << endl;
    }
    
    // try {
    //     unique_ptr<Foo> f = bar(0);
    // } catch(const std::invalid_argument& e) {
    //     cerr << e.what() << endl;
    // }

    // try {
    //     unique_ptr<Foo> f = bar(0);
    // } catch(...) {
    //     cerr << "execption occured" << endl;
    // }

    // try {
    //     int result = divide(10, 0);
    //     cout << result << endl;
    // } catch(const std::invalid_argument& e) {
    //     std::cerr << e.what() << '\n';
    // }

    // auto result = divide(10, 0);
    // if (holds_alternative<int>(result)) {
    //     cout << get<int>(result) << endl;
    // } else {
    //     cout << get<string>(result) << endl;
    // }

    // int r = divide(10,3);
    // cout << r << endl;
    // int result;
    // if (divide(10, 0, result)) {
    //     cout << result << endl;
    // }

    // auto result = divide(10, 5);
    // if (result.has_value()) {
    //     cout << result.value() << endl;
    // }
    // result = divide(10, 0);
    // if (result.has_value()) {
    //     cout << result.value() << endl;
    // }
    return 0;
}
