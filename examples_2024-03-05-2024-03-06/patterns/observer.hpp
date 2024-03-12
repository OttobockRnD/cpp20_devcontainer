#include <vector>
#include <string>

class NewsSubscriber {
    public:
        virtual void update(std::string news) = 0;
};

class NewsPublisher { 
    private:
        std::vector<NewsSubscriber*> subscribers;
    public: 
        void subscribe(NewsSubscriber* subscriber) {
            subscribers.push_back(subscriber);
        }
        void unsubscribe(NewsSubscriber* subscriber) {
            subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
        }
        void publish(std::string news) {
            for (auto subscriber : subscribers) {
                subscriber->update(news);
            }
        }
};

class NewsReceiver1 : public NewsSubscriber {
    public:
        void update(std::string news) override {
            std::cout << "Received news: " << news << std::endl;
        }
};

class NewsReceiver2 : public NewsSubscriber {
    public:
        void update(std::string news) override {
            std::cout << "Received news: " << news << std::endl;
        }
};
