#include <iostream>
#include <stdexcept>
#include <memory>
#include "stack.hpp"

Stack::Stack(int size) : _size(size), _tos(0), _pData(std::make_unique<int[]>(size)) {}

bool Stack::isEmpty() const {
    return _tos == 0;
}

bool Stack::isFull() const {
    return _tos == _size;
}

void Stack::push(int value) {
    if (isFull()) {
        throw std::out_of_range{"Stack is full"};
    }
    _pData[_tos++] = value;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::out_of_range{"Stack is empty"};
    }
    return _pData[--_tos];
}

