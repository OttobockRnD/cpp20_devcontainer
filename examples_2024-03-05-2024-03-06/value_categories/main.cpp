#include <iostream>

//see: https://stackoverflow.com/questions/16637945/empirically-determine-value-category-of-c11-expression
template<typename T>
struct value_category {
    static constexpr auto value = "prvalue";
};

template<typename T>
struct value_category<T&> {
    static constexpr auto value = "lvalue";
};

template<typename T>
struct value_category<T&&> {
    static constexpr auto value = "xvalue";
};

#define VALUE_CATEGORY(expr) value_category<decltype((expr))>::value

int main(int argc, char const *argv[]) {
    std::cout << VALUE_CATEGORY(argc) << std::endl;
    std::cout << VALUE_CATEGORY(42) << std::endl;
    std::cout << VALUE_CATEGORY(std::move(42)) << std::endl;
    return 0;
}
