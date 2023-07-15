#include "Observer.hpp"
#include <iostream>

int main() {
    Weather_Station ws;
    User_Interface ui;
    Alert_System alerter;
    Logger logger;

    ws.register_observer(ui);
    ws.register_observer(alerter);
    ws.register_observer(logger);

    ws.set_temp(65);
    ws.set_pressure(15);
    ws.set_wind_speed(15);

    ws.set_pressure(35);
    ws.remove_observer(alerter);
    ws.set_wind_speed(77);
}
