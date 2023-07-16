// Author: Jarret Crittendon
// 2023 JUL 15
// Overview:  Challenge Problem for LinkedIn Learning Course,
// "Programming Foundations: Design Patterns" - implementing the Observer
// pattern

#include <set>
#include <memory>
#include <iostream>
#include <fstream>

class Subject;

class Observer {
public:
    virtual void update() = 0;

    virtual ~Observer() { }
};

class Subject {
public:
    virtual void register_observer(Observer& observer) = 0;
    virtual void remove_observer(Observer& observer) = 0;
    virtual void notify_observers() = 0;

    virtual ~Subject() { }
};

class Weather_Station : public Subject {
public:
    Weather_Station():
        temperature(0), wind_speed(0), pressure(0) { }

    // Since these change state, each setter should update observers
    void set_temp(double temp) {
        temperature = temp;
        notify_observers();
    }
    void set_wind_speed(double wind) {
        wind_speed = wind;
        notify_observers();
    }
    void set_pressure(double prs) {
        pressure = prs;
        notify_observers();
    }

    double get_temp() const {
        return temperature;
    };
    double get_wind_speed() const {
        return wind_speed;
    }
    double get_pressure() const {
        return pressure;
    }

    void register_observer(Observer& observer) override {
        observers.insert(&observer);
    }
    void remove_observer(Observer& observer) override {
        observers.erase(&observer);
    }
    void notify_observers() override {
        for (auto observer : observers) {
            observer->update();
        }
    }

private:
    double temperature;
    double wind_speed;
    double pressure;

    std::set<Observer*> observers;
};

class User_Interface : public Observer {
public:
    User_Interface(Weather_Station& ws):
        station(ws) { };

    void update() override {
        display();
    }

    void display() const {
        std::cout << "New Information!\n";
        std::cout << "Temperature: " << station.get_temp() << std::endl;
        std::cout << "Wind Speed: " << station.get_wind_speed() << std::endl;
        std::cout << "Pressure: " << station.get_pressure() << std::endl;
        std::cout << std::endl;
    }

private:
    Weather_Station& station;
};

class Logger : public Observer {
public:
    Logger(Weather_Station& ws):
        update_count(0), station(ws)
        { logfile.open("./res/log.txt"); }

    void update() override {
        log();
    }

    void log()  {
        update_count++;
        logfile << "Update " << update_count << "\n";
        logfile << "Temperature: " << station.get_temp() << std::endl;
        logfile << "Wind Speed: " << station.get_wind_speed() << std::endl;
        logfile << "Pressure: " << station.get_pressure() << std::endl;
        logfile << std::endl;
    }

    ~Logger() { logfile.close(); }

private:
    std::ofstream logfile;
    int update_count;
    Weather_Station& station;
};

class Alert_System : public Observer {
public:
    Alert_System(Weather_Station& ws):
        station(ws) { }

    void update() override {
        alert();
    }

    void alert() const {
        const auto current_temp = std::abs(station.get_temp() - danger_temp);
        const auto current_wind = std::abs(station.get_wind_speed() - danger_wind);
        const auto current_pressure = std::abs(station.get_pressure() - danger_pressure);

        std::cout << "CURRENT STATUS\n";
        if (station.get_temp() >= danger_temp) {
            std::cout << "ALERT! Current temperature is " << current_temp
                      << " above safe levels. Keep cool!" << std::endl;
        } else {
            std::cout << "Temperature is at a safe level." << std::endl;
        }

        if (station.get_wind_speed() >= danger_wind) {
            std::cout << "ALERT! Current wind speed is " << current_wind
                      << " above safe levels. Stay indoors!" << std::endl;
        } else {
            std::cout << "Wind speeds are at a safe level." << std::endl;
        }

        if (station.get_pressure() >= danger_pressure) {
            std::cout << "ALERT! Air pressure is " << current_pressure
                      << " above safe levels for humans. Get to a safer"
                      << " altitude!" << std::endl;
        } else {
            std::cout << "Air pressure is at a confortable level." << std::endl;
        }

        std::cout << std::endl;
    }

private:
    const double danger_temp = 99.0;
    const double danger_wind = 75.0;
    const double danger_pressure = 35.0;

    Weather_Station& station;
};