#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print(string s) {
    std::cout << s << endl;
}

bool isNegative(int i) {
    return i < 0;
}

double getMeasurment() {
    return 3.14;
}

class Lambda123 {
    public:
        Lambda123() {}
        template<typename T, typename U>
        auto operator() (T x, U y) const{
            return x < y ? x : y;
        }
};

class Foo {};

bool biggerThan3(int i) {
    return i > 3;
}

int foo(int t) {
    std::cout << "foo " << t << std::endl;
    return 42;
}

int main(int argc, char const *argv[]) {
    // auto square = [](int x) { return x * x; };
    // cout << square(3) << endl;

    // // --------------------------------------------------------------------------------
    // vector<int> v {-11, 37, 3, 0, 7, 13, 6, 8, -3, -5, 4};
    // int threshold = -1;
    // int count = count_if(v.begin(), v.end(), [threshold](int i) { return i > threshold; });
    // cout << count << endl;

    // count = count_if(v.begin(), v.end(), biggerThan3);
    // cout << count << endl;

    // // --------------------------------------------------------------------------------
    // double measurment = getMeasurment();
    // auto scale = [measurment] (double x) { 
    //     return x * measurment; 
    // };
    // cout << scale(3.0) << endl;
    // cout << scale.operator()(3.0) << endl;
    // // --------------------------------------------------------------------------------

    // auto min = [] (auto x, auto y) { 
    //     return x < y ? x : y; 
    // };
    // cout << min(string{"hello"}, string{"world"}) << endl;
    // cout << min(3.1, 4) << endl;
    // const char* s1 = "hello";
    // const char* s2 = "world";
    // cout << min(s1, s2) << endl;
    // // min(Foo{}, Foo{}); //will not compile - no operator< for Foo

    // cout << &s1 << endl;
    // cout << &s2 << endl;

    // cout << min.operator()<double, int>(3.1, 4) << endl;

    // // --------------------------------------------------------------------------------
    // auto halve = [](int x) -> double {
    //     if (x % 2 == 0) {
    //         return x / 2;
    //     } else {
    //         return x / 2.0;
    //     }
    // };

    // cout << halve(10.0) << endl;
    // // --------------------------------------------------------------------------------
    
    vector<int> v {42, -11, 13, 0, 7, 1111};

    bool result = any_of(v.begin(), v.end(), [](int i) { return i < 0; });
    cout << result << endl;
    result = any_of(v.begin(), v.end(), isNegative);
    cout << result << endl;

    int x = 10;
    auto timesX = [x](int i) { return i * x; };
    timesX(24);

    auto timesTwo = [x = 2] (int i) { return i * x; };
    cout << timesTwo(21) << endl;

    auto foo = [x = 0] () mutable { 
        while (x < 5) {
            cout << x << endl;
            x++;
        }
    };
    foo();
    foo(); // will product no output as lambda foo stored the state of the captured variable x

    auto min = [](int x, int y) { 
        return x < y ? x : y; 
    };
    cout << min(3, 4) << endl;
    cout << min.operator()(3, 4) << endl;

    return 0;
}


