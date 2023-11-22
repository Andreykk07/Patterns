#include <iostream>

class AbstractProductA {
public:
    virtual void useA() = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
    void useA() override {
        std::cout << "Використано продукт A1" << std::endl;
    }
};

class ConcreteProductA2 : public AbstractProductA {
public:
    void useA() override {
        std::cout << "Використано продукт A2" << std::endl;
    }
};

class AbstractProductB {
public:
    virtual void useB() = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
    void useB() override {
        std::cout << "Використано продукт B1" << std::endl;
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    void useB() override {
        std::cout << "Використано продукт B2" << std::endl;
    }
};

class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ConcreteProductB2();
    }
};

int main() {
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();
    
    productA1->useA();
    productB1->useB();

    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();

    productA2->useA();
    productB2->useB();

    delete factory1;
    delete productA1;
    delete productB1;
    
    delete factory2;
    delete productA2;
    delete productB2;

    return 0;
}
