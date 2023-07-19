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
    Pizza(std::string desc, double money):
        description(desc), price(money) { }

    virtual double cost() = 0;

    virtual ~Pizza() { }

protected:
    std::string description;
    double price;
};

class ThinCrustPizza : public Pizza {
public:
    ThinCrustPizza():
        Pizza("Thin crust pizza", 7.99) { }

private:

};

class ThickCrustPizza : public Pizza {
public:
    ThickCrustPizza():
        Pizza("Thick crust pizza", 9.99) { }

private:

};

// Toppings - Decorator class

class Toppings : public Pizza {
public:
    Toppings() = default;
    virtual double cost() override = 0;

    virtual ~Toppings() { }
protected:
    Pizza& pizza;
};

class Cheese : public Toppings {
public:
    Cheese() = default;

private:

};

class Olives : public Toppings {

};

class Peppers : public Toppings {

};