#include <iostream>
#include <string>

class NewSystemInterface {
public:
    virtual ~NewSystemInterface() {}
    virtual void newRequest() const = 0;
};

class OldSystem {
public:
    void oldRequest() const {
        std::cout << "Old System Request" << std::endl;
    }
};

class Adapter : public NewSystemInterface {
private:
    OldSystem oldObj;

public:
    void newRequest() const override {
        oldObj.oldRequest();
    }
};

class Client {
public:
    void executeRequest(const NewSystemInterface& system) const {
        system.newRequest();
    }
};

int main() {
    Adapter adapter; 
    Client client;  

    client.executeRequest(adapter); 

    return 0;
}
