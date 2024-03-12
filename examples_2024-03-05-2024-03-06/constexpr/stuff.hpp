#include <type_traits>
#include <iostream>

template<int n>
constexpr int fibonacci() {
    if constexpr (n >= 2) {
        return fibonacci<n - 1>() + fibonacci<n - 2>();
    }
    else {
        return n;
    }
}

consteval uint64_t square(uint32_t n) {
    if (std::is_constant_evaluated()) {
        return n * n;
    }
    return 0;
}

template<uint32_t base, uint32_t n>
constexpr uint64_t powN() {
    if (!std::is_constant_evaluated()) {
        return 0;
    }
    uint32_t exp = n;
    uint64_t result = base;
    while (--exp > 0) {
        result *= base;
    }
    return result;
}