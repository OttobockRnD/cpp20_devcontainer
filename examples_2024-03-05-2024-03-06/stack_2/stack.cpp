#include <iostream>
#include <cstring>
#include "stack.hpp"

Stack::Stack(int size): _size(size), _tos(0), _pData(new int[size]) {}

Stack::Stack(const Stack& s): _size(s._size), _tos(s._tos), _pData(new int[s._size]) {
    std::cout << "copy constructor called" << std::endl;
    std::memcpy(_pData, s._pData, s._size * sizeof(int));
}

Stack& Stack::operator=(const Stack& rhs) {
    std::cout << "copy assignment called" << std::endl;
    if (this != &rhs) {
        delete[] this->_pData;
        this->_pData = new int[rhs._size];
        this->_size = rhs._size;
        this->_tos = rhs._tos;
        std::memcpy(_pData, rhs._pData, rhs._size * sizeof(int));
    }
    return *this;
}

Stack::Stack(Stack&& s): _size(s._size), _tos(s._tos), _pData(s._pData) {
    std::cout << "move constructor called" << std::endl;
    s._pData = nullptr;
    s._size = 0;
    s._tos = 0;
}

Stack& Stack::operator=(Stack&& rhs) {
    std::cout << "move assignment called" << std::endl;
    if (this != &rhs) {
        delete[] this->_pData;
        this->_pData = rhs._pData;
        this->_size = rhs._size;
        this->_tos = rhs._tos;
        rhs._pData = nullptr;
        rhs._size = 0;
        rhs._tos = 0;
    }
    return *this; 
}

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
        std::cout << "empty - we will fix this" << std::endl;
        return 42;
    }
    return _pData[--_tos];
}