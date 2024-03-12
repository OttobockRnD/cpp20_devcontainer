#include <iostream>

// void myPrintf() {
//     std::cout << std::endl;
// }

// template <typename T> void myPrintf(const T& t) {
//     std::cout << t << std::endl;
// }

// template <typename Initial, typename... Args> 
// void myPrintf(const Initial& initial, const Args&... args) {
//     std::cout << initial << ", ";
//     myPrintf(args...);
// }

template <typename Initial, typename... Args> 
void myPrintf(const Initial& initial, const Args&... args) {
    std::cout << initial << " ";
    if constexpr (sizeof...(args) > 0) {
        myPrintf(args...);
    }
}