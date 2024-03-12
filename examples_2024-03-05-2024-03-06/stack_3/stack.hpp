#include <memory>

class Stack {
    private:
        std::unique_ptr<int[]> _pData;
        int _tos;
        int _size;
    public:
        Stack(int size = 16);

        void push(int v);
        int pop();
        bool isFull() const;
        bool isEmpty() const;
};