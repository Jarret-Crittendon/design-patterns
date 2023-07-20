#include <iostream>
#include "Decorator.hpp"

int main() {
    ThickCrustPizza pie;
    Pizza& pizza = pie;
    std::cout << pizza.get_desc() << std::endl;
    pizza = Cheese(pizza);
    std::cout << pizza.get_desc() << std::endl;
    pizza = Cheese(pizza);
    std::cout << pizza.get_desc() << std::endl;
    pizza = Peppers(pizza);

    std::cout << "I'm ordering a " << pizza.get_desc() << std::endl;
    std::cout << "It costs $" << pizza.cost() << std::endl;
}