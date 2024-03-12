#include <iostream>

class CommunicationProtocol {
    public:
        virtual void sendData(const std::vector<uint8_t>& data) = 0;
        virtual ~CommunicationProtocol() = default;
};

class ExistingBinaryProtocol : public CommunicationProtocol {
    public:
        void sendData(const std::vector<uint8_t>& data) override {
            std::cout << "Transmitting binary data..." << std::endl;
        }
};

class JSONProtocol {
    public:
        void transmitData(const std::string& data) {
            std::cout << "Transmitting JSON data: " << data << std::endl;
        }
};

class JSONToBinaryAdapter : public CommunicationProtocol {
    private:
        std::unique_ptr<JSONProtocol> protocol;
    public:
        JSONToBinaryAdapter() : protocol(std::make_unique<JSONProtocol>()) {}

        void sendData(const std::vector<uint8_t>& data) override {
            std::string jsonData = convertBinaryToJson(data);
            protocol->transmitData(jsonData);
        }

        std::string convertBinaryToJson(const std::vector<uint8_t>& data) {
            return "0xDEADBEEF";
        }
};