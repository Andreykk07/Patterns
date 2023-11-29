#include <iostream>

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance; 
        return instance;
    }

    void someMethod() {
        std::cout << "Виклик методу класу Singleton" << std::endl;
    }

private:
    Singleton() {}
    
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    Singleton& instance = Singleton::getInstance();
    
    instance.someMethod();

    return 0;
}
