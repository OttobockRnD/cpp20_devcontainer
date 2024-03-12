#include <iostream>
#include <string>
#include "forwarding.hpp"

using namespace std;

void print(string s) {
    std::cout << s << endl;
}

int main(int argc, char const *argv[]) {
    LogCommandInvoker logCommandInvoker;
    SimpleCommand command(print, "Hello, World!");
    const SimpleCommand constCommand(print, "const Hello, World!");

    logCommandInvoker.Execute(command);
    logCommandInvoker.Execute(constCommand);
    logCommandInvoker.Execute(SimpleCommand(print, "rvalue Hello, World!"));

    return 0;
}
