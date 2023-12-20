#include <iostream>

class Singleton {
public:
    static Singleton& getInstance() {
        if (!instanceCreated) {
            instanceCreated = true;
            static Singleton instance;
            return instance;
        } else {
            static Singleton existingInstance;
            return existingInstance;
        }
    }

    void someMethod() {
        std::cout << "Виклик методу класу Singleton" << std::endl;
    }

private:
    Singleton() {}
    static bool instanceCreated;

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

bool Singleton::instanceCreated = false;

int main() {
    Singleton& instance1 = Singleton::getInstance();
    instance1.someMethod();

    Singleton& instance2 = Singleton::getInstance();
    instance2.someMethod(); 

    return 0;
}
