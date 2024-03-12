#include <memory>

template<typename T>
class Stack {
    private:
        int _size;
        int _tos {0};
        std::unique_ptr<T[]> _pData;
    public:

        Stack(int size=16) : _size(size), _tos(0), _pData(std::make_unique<T[]>(size)) {}

        bool isEmpty() const {
            return _tos == 0;
        }

        bool isFull() const {
            return _tos == _size;
        }

        bool push(T value) {
            if (isFull()) {
                return false;
            }
            _pData[_tos++] = value;
            return true;
        }

        T pop() {
            if (isEmpty()) {
                return 42;
            }
            return _pData[--_tos];
        }
};