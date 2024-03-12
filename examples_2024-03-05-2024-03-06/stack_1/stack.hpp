class Stack {
    private:
        int* _pData;
        int _tos;
        int _size;
    public:
        Stack(int size);
        ~Stack();

        bool push(int v);
        int pop();
        bool isFull() const;
        bool isEmpty() const;
};