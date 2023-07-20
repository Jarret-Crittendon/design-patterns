#include <iostream>
#include <memory>
#include "Decorator.hpp"

int main() {
    std::shared_ptr<Pizza> pizza = std::make_shared<ThickCrustPizza>();
    pizza = std::make_shared<Cheese>(pizza);
    pizza = std::make_shared<Olives>(pizza);
    pizza = std::make_shared<Peppers>(pizza);

    std::cout << "I'm ordering a " << pizza->get_desc() << std::endl;
    std::cout << "It costs $" << pizza->cost() << std::endl;
}