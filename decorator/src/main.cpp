#include <iostream>
#include "Decorator.hpp"

int main() {
    std::shared_ptr<Pizza> pizza = std::make_shared<ThickCrustPizza>();
    std::cout << pizza->get_desc() << std::endl;
    pizza = make_shared<Cheese>(pizza);
    std::cout << pizza->get_desc() << std::endl;
    pizza = make_shared<Cheese>(pizza);
    std::cout << pizza->get_desc() << std::endl;
    pizza = make_shared<Peppers>(pizza);

    std::cout << "I'm ordering a " << pizza->get_desc() << std::endl;
    std::cout << "It costs $" << pizza->cost() << std::endl;
}