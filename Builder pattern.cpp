#include <iostream>
#include <string>

class Pizza {
public:
    void setDough(const std::string& dough) {
        dough_ = dough;
    }

    void setSauce(const std::string& sauce) {
        sauce_ = sauce;
    }

    void setTopping(const std::string& topping) {
        topping_ = topping;
    }

    void displayPizza() const {
        std::cout << "Pizza with Dough: " << dough_
                  << ", Sauce: " << sauce_
                  << ", Topping: " << topping_
                  << std::endl;
    }

private:
    std::string dough_;
    std::string sauce_;
    std::string topping_;
};

class PizzaBuilder {
public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza* getPizza() = 0;
};

class MargheritaPizzaBuilder : public PizzaBuilder {
public:
    void buildDough() override {
        pizza_->setDough("thin crust");
    }

    void buildSauce() override {
        pizza_->setSauce("tomato");
    }

    void buildTopping() override {
        pizza_->setTopping("mozzarella cheese");
    }

    Pizza* getPizza() override {
        return pizza_;
    }

private:
    Pizza* pizza_ = new Pizza();
};

class Cook {
public:
    void setPizzaBuilder(PizzaBuilder* builder) {
        pizzaBuilder_ = builder;
    }

    Pizza* getPizza() {
        return pizzaBuilder_->getPizza();
    }

    void constructPizza() {
        pizzaBuilder_->buildDough();
        pizzaBuilder_->buildSauce();
        pizzaBuilder_->buildTopping();
    }

private:
    PizzaBuilder* pizzaBuilder_;
};

int main() {
    Cook cook;

    MargheritaPizzaBuilder margheritaBuilder;
    cook.setPizzaBuilder(&margheritaBuilder);
    
    cook.constructPizza();
    Pizza* margheritaPizza = cook.getPizza();
    margheritaPizza->displayPizza();

    delete margheritaPizza;

    return 0;
}
