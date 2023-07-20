// Author: Jarret Crittendon
// 2023 JUL 19
// Overview:  Challenge Problem for LinkedIn Learning Course,
// "Programming Foundations: Design Patterns" - implementing the Observer
// pattern

// ThinCrustPizza, ThickCrustPizza
// Toppings: Cheese, Olives, Peppers

#include <string>

class Pizza {
public:
    Pizza() = default;

    virtual double cost() const = 0;

    std::string get_desc() const {
        return description;
    }

    virtual ~Pizza() { }

protected:
    std::string description;
};




class ThinCrustPizza : public Pizza {
public:
    ThinCrustPizza()
        { description = "Thin crust pizza"; }

        double cost() const override {
            return 7.99;
        }
};

class ThickCrustPizza : public Pizza {
public:
    ThickCrustPizza()
        { description = "Thick crust pizza"; }

        double cost() const override {
            return 10.99;
        }
};

// Toppings - Decorator class

class Toppings : public Pizza {
public:
    Toppings(const Pizza& pz):
        pizza(pz) { }
    
    virtual std::string get_desc() const = 0;

    virtual ~Toppings() { }
protected:
    const Pizza& pizza;
};

class Cheese : public Toppings {
public:
    Cheese(const Pizza& pz):
        Toppings(pz) { }

    double cost() const override {
        return pizza.cost() + 1.05;
    }

    std::string get_desc() const override {
        return pizza.get_desc() + ", extra cheese";
    }
};

class Olives : public Toppings {
public: 
    Olives(const Pizza& pz):
        Toppings(pz) { }

    double cost() const override {
        return pizza.cost() + 0.99;
    }

    std::string get_desc() const override {
        return pizza.get_desc() + ", olives";
    }
};

class Peppers : public Toppings {
public: 
    Peppers(const Pizza& pz):
        Toppings(pz) { }

    double cost() const override {
        return pizza.cost() + 0.50;
    }

    std::string get_desc() const override {
        return pizza.get_desc() + ", peppers";
    }
};