#ifndef DUCK_H
#define DUCK_H

#include <iostream>

enum FlyType { wings, none };
enum QuackType { loud, silent, squeak };

//Flying

class FlyBehavior {
public:
    virtual void fly() const = 0;

    virtual ~FlyBehavior() = default;
};

class FlyWithWings : public FlyBehavior {
public:
    virtual void fly() const override {
        std::cout << "This duck uses its wings to fly high.\n";
    }
};

class FlyNoWay : public FlyBehavior {
public:
    virtual void fly() const override {
        std::cout << "This duck cannot fly.\n";
    }
};

// Quacking

class QuackBehavior {
public:
    virtual void quack() const = 0;

    virtual ~QuackBehavior() = default;
};

class LoudQuack : public QuackBehavior {
public:
    virtual void quack() const override {
        std::cout << "This duck releases a high-volume quack.\n";
    }
};

class QuackNoWay : public QuackBehavior {
public:
    virtual void quack() const override {
        std::cout << "This duck cannot quack.\n";
    }
};

class Squeak : public QuackBehavior {
public:
    virtual void quack() const override {
        std::cout << "This duck squeaks.\n";
    }
};


// Duck

class Duck {
public:
    Duck() = default;
    Duck(const FlyType& ftype, const QuackType& qtype) {
        set_fly(ftype);
        set_quack(qtype);
    };


    virtual void perform_fly() const;
    virtual void perform_quack() const;
    virtual void swim() const;
    virtual void display() const = 0;

    virtual ~Duck() {
        delete fly_action;
        delete quack_action;
    }

protected:
    void set_fly(FlyType);
    void set_quack(QuackType);

    FlyBehavior* fly_action = nullptr;
    QuackBehavior* quack_action = nullptr;
};

void Duck::set_fly(FlyType ftype) {
    switch (ftype) {
        case wings: {
            fly_action = new FlyWithWings;
            break;
        }

        case none: {
            fly_action = new FlyNoWay;
            break;
        }
    }
}

void Duck::set_quack(QuackType qtype) {
    switch (qtype) {
        case loud: {
            quack_action = new LoudQuack;
            break;
        }

        case silent: {
            quack_action = new QuackNoWay;
            break;
        }

        case squeak: {
            quack_action = new Squeak;
            break;
        }
    }
}

void Duck::perform_fly() const {
    fly_action->fly();
}

void Duck::perform_quack() const {
    quack_action->quack();
}

void Duck::swim() const {
    std::cout << "This duck merrily swims.\n";
}

// Some Ducks

class MallardDuck : public Duck {
public:
    MallardDuck():
        Duck(wings, loud) { }
    
    virtual void display() const override {
        std::cout << "A brown mallard duck.\n";
    }
};

class RubberDuck : public Duck {
public:
    RubberDuck():
        Duck(none, squeak) { }
    
    virtual void display() const override {
        std::cout << "A canary yellow rubber duck.\n";
    }
};

class DecoyDuck : public Duck {
public:
    DecoyDuck():
        Duck(none, silent) { }
    
    virtual void display() const override {
        std::cout << "A featureless decoy duck.\n";
    }
};

#endif