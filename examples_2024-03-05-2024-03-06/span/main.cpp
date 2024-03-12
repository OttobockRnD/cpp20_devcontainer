#include <span>
#include <iostream>

void f(int* data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << data[i] << std::endl;
    }
}

void f(std::span<int> data) {
    for (size_t i = 0; i < data.size(); i++) {
        std::cout << data[i] << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    int data[] = {1,2,3,4,5};
    f(data, 5);
    f(data);
    return 0;
}