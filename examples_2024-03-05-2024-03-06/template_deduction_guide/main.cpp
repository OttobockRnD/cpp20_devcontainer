template <typename T, typename U>
class MyTuple {
    public:
        T v1{};
        U v2{};
};

// needed pre c++20
// template <typename T, typename U>
// MyTuple(T, U) -> MyTuple<T, U>;


int main(int argc, char const *argv[]) {
    MyTuple t {1, 2.3};

    return 0;
}
