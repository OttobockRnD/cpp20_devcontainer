#include <iostream>

class ADCSamplingStrategy {
    public:
        virtual ~ADCSamplingStrategy() = default;
        virtual int sample() = 0;
};

class SingleShotSamplingStrategy : public ADCSamplingStrategy {
    public:
        int sample() override {
            std::cout << "Single-shot sampling..." << std::endl;
            return 0;
        }
};

class ContinuousSamplingStrategy : public ADCSamplingStrategy {
public:
    int sample() override {
        std::cout << "Continuous sampling..." << std::endl;
        return 0;
    }
};

class ADCDriver {
    private:
        std::unique_ptr<ADCSamplingStrategy> strategy;
    public:
        ADCDriver(std::unique_ptr<ADCSamplingStrategy> strategy) : strategy(std::move(strategy)) {}

        void setSamplingStrategy(std::unique_ptr<ADCSamplingStrategy> newStrategy) {
            strategy = std::move(newStrategy);
        }

        int sample() {
            return strategy->sample();
        }
};
