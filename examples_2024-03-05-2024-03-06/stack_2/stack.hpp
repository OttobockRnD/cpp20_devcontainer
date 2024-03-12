class Stack {
    private:
        int* _pData;
        int _tos;
        int _size;
    public:
        Stack(int size);
        Stack(const Stack&);
        Stack(Stack&&);
        Stack& operator=(const Stack&);
        Stack& operator=(Stack&& rhs);
        ~Stack();

        bool push(int v);
        int pop();
        bool isFull() const;
        bool isEmpty() const;
};