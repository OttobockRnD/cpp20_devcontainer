#include <iostream>
#include <cstring>
#include "stack.hpp"

Stack::Stack(int size): _size(size), _tos(0), _pData(new int[size]) {}

Stack::~Stack() {
    if (_pData != nullptr) {
        std::cout << "freeing: " << _pData << std::endl;
        delete[] _pData;
    }
}

bool Stack::isEmpty() const {
    return _tos == 0;
}

bool Stack::isFull() const {
    return _tos == _size;
}

bool Stack::push(int value) {
    if (isFull()) {
        return false;
    }
    _pData[_tos++] = value;
    return true;
}

int Stack::pop() {
    if (isEmpty()) {
        return 42;
    }
    return _pData[--_tos];
}