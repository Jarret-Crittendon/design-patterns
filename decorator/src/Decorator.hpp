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
    Pizza(const Pizza& rhs):
        description(rhs.description) { }

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
    explicit Toppings(std::shared_ptr<Pizza> pz):
        pizza(pz) { }
    
    virtual std::string get_desc() const = 0;

    virtual ~Toppings() { }
protected:
    std::shared_ptr<Pizza> pizza;
};

class Cheese : public Toppings {
public:
    explicit Cheese(std::shared_ptr<Pizza> pz):
        Toppings(pz) { }

    double cost() const override {
        return pizza->cost() + 1.05;
    }

    std::string get_desc() const override {
        return pizza->get_desc() + ", extra cheese";
    }
};

class Olives : public Toppings {
public: 
    explicit Olives(std::shared_ptr<Pizza> pz):
        Toppings(pz) { }

    double cost() const override {
        return pizza->cost() + 0.75;
    }

    std::string get_desc() const override {
        return pizza->get_desc() + ", olives";
    }
};

class Peppers : public Toppings {
public: 
    explicit Peppers(std::shared_ptr<Pizza> pz):
        Toppings(pz) { }

    double cost() const override {
        return pizza->cost() + 0.50;
    }

    std::string get_desc() const override {
        return pizza->get_desc() + ", peppers";
    }
};