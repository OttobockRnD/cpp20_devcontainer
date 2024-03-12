template<typename T, size_t SIZE>
class Stack {
    private:
        T _data[SIZE];
        int _tos {0};
    public:

        /**
         * Checks if the stack is empty.
         * 
         * @return true if the stack is empty, false otherwise.
         */
        bool isEmpty() const {
            return _tos == 0;
        }

        /**
         * Checks if the stack is full.
         * 
         * @return true if the stack is full, false otherwise.
         */
        bool isFull() const {
            return _tos == SIZE;
        }

        /**
         * Pushes a value onto the stack.
         * 
         * @param value The value to be pushed onto the stack.
         * @throws std::out_of_range if the stack is full.
         */
        void push(T value) {
            if (isFull()) {
                throw std::out_of_range{"Stack is full"};
            }
            _data[_tos++] = value;
        }

        /**
         * Pops the top value from the stack.
         * 
         * @return The top value of the stack.
         * @throws std::out_of_range if the stack is empty.
         */
        T pop() {
            if (isEmpty()) {
                throw std::out_of_range{"Stack is empty"};
            }
            return _data[--_tos];
        }

        /**
         * Returns the size of the stack.
         * 
         * @return The size of the stack.
         */
        size_t size() { return SIZE; }
};

template<typename T, size_t size = 32>
Stack<T, size> createDefaultStack() {
    return Stack<T, size>{};
}