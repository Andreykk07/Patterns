#include <iostream>
#include <string>

class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void display() const = 0;
    virtual ~Prototype() {}
};

class ConcretePrototype : public Prototype {
private:
    int data;

public:
    ConcretePrototype(int value) : data(value) {}

    ConcretePrototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void display() const override {
        std::cout << "ConcretePrototype with data: " << data << std::endl;
    }
};

int main() {
    ConcretePrototype original(42);

    ConcretePrototype* clone = original.clone();

    original.display();
    clone->display();

    delete clone;

    return 0;
}
