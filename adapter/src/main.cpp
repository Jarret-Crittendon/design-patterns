// Author: Jarret Crittendon
// Date: 2023 JAN 06
// Challenge: Use the adapter pattern to adapt a Drone class to
// the Duck class.

#include "Duck.hpp"
#include "Drone.hpp"

void test_duck(const Duck& duck) {
    duck.display();
    duck.perform_fly();
    duck.perform_quack();
}

int main()
{
    const RubberDuck rd;
    const MallardDuck md;
    const DecoyDuck dd;
    const Drone buzz;
    const DroneAdapter dbz(buzz);

    test_duck(dd);

    std::cout << "\n\n";

    test_duck(md);

    std::cout << "\n\n";

    test_duck(rd);

    std::cout << "\n\n";

    test_duck(dbz);
}
