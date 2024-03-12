#include <functional>
#include <memory>
#include <string>

class Command {
    public:
    virtual void Execute() const = 0;
};

class SimpleCommand : public Command {
    private:
        std::string _param;
        std::function<void(std::string)> _receiver;
    public:
        SimpleCommand(std::function<void(std::string)> receiver, std::string param): _receiver(receiver), _param(param) {}
        void Execute() const override{
            _receiver(_param);
        }
};

class CommandInvoker {
    public:
        virtual void Execute(Command& command) {
            std::cout << "CommandInvoker::Execute(Command&)" << std::endl;
            command.Execute();
        }

        virtual void Execute(const Command& command) {
            std::cout << "CommandInvoker::Execute(const Command&)" << std::endl;
            command.Execute();
        }

        virtual void Execute(Command&& command) {
            std::cout << "CommandInvoker::Execute(Command&&)" << std::endl;
            command.Execute();
        }
};

class LogCommandInvoker : public CommandInvoker{
    public:
        template<typename T>
        void Execute(T&& command) {
            std::cout << "template LogCommandInvoker(T&&) with forward reference" << std::endl;
            CommandInvoker::Execute(std::forward<T>(command));
        }
};

// class LogCommandInvoker : public CommandInvoker{
//     public:
//         void Execute(Command& command) {
//             std::cout << "LogCommandInvoker::Execute(Command&)" << std::endl;
//             CommandInvoker::Execute(command);
//         }

//         void Execute(const Command& command) {
//             std::cout << "LogCommandInvoker::Execute(const Command&)" << std::endl;
//             CommandInvoker::Execute(command);
//         }

//         void Execute(Command&& command) {
//             std::cout << "LogCommandInvoker::Execute(Command&&)" << std::endl;
//             CommandInvoker::Execute(std::move(command));
//         }
// };
