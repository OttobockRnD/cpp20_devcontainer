class CellularModule {
public:
    virtual void powerOn() = 0;
    virtual bool isPoweredOn() = 0;
    virtual void searchForNetworks() = 0;
    virtual bool isRegisteredInNetwork() = 0;
    virtual bool createPDPContext() = 0;
};

class ModuleA : public CellularModule {
    bool _isPoweredOn = false;
    bool _registeredInNetwork = false;
public:
    void powerOn() override {
        std::cout << "Powering on module A..." << std::endl;
        _isPoweredOn = true;
    }
    bool isPoweredOn() override {
        return _isPoweredOn;
    }
    void searchForNetworks() override {
        std::cout << "Searching for networks with module A..." << std::endl;
        _registeredInNetwork = true;
    }
    bool isRegisteredInNetwork() override {
        return _registeredInNetwork;
    }
    bool createPDPContext() override {
        std::cout << "Creating PDP context with module A..." << std::endl;
        return true;
    }
};

class CellularFacade {
    private:
            std::unique_ptr<CellularModule> _module;
    public:
        CellularFacade(CellularModule* module) : _module(module) {}
            
        void powerOn() {
            if (!_module->isPoweredOn()) {
                _module->powerOn();
            }
        }

        bool connect() {
            if (!_module->isPoweredOn()) {
                _module->powerOn();
            }
            if (!_module->isRegisteredInNetwork()) {
                _module->searchForNetworks();
            }
            return _module->createPDPContext();
        }
};