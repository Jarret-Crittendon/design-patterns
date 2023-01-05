
// Author: Jarret Crittendon
// Overview:  Challenge Problem for LinkedIn Learning Course,
// "Programming Foundations: Design Patterns" - implementing the Strategy
// pattern

// Share photos by text, email, and social media

#include <iostream>

class ShareBehavior {
public:
    virtual void share() = 0;

    virtual ~ShareBehavior() = default;
};

class Email: public ShareBehavior {
public:
    virtual void share() override {
        std::cout << "Photo sent to your email account.\n";
    };
};

class Text: public ShareBehavior {
public:
    virtual void share() override {
        std::cout << "Photo sent via text to the indicated phone number.\n";
    };
};

class Social_Media: public ShareBehavior {
public:
    virtual void share() override {
        std::cout << "Photo posted to the indicated social media platform.\n";
    };
};

class PhoneCameraApp {
public:
    PhoneCameraApp(ShareBehavior* behavior):
        share_action(behavior) {}
    void take();
    virtual void edit() = 0;
    void save();
    void perform_share();
    void set_share(ShareBehavior* new_behavior);

    virtual ~PhoneCameraApp() {
        delete share_action;
    };

protected:

    ShareBehavior* share_action;
};

void PhoneCameraApp::take() {
    std::cout << "Took a picture!\n";
}

void PhoneCameraApp::save() {
    std::cout << "Saved picture.\n";
}

void PhoneCameraApp::perform_share() {
    share_action->share();
}

void PhoneCameraApp::set_share(ShareBehavior* new_behavior) {
    if (new_behavior != nullptr || new_behavior != share_action) {
        delete share_action;
        share_action = new_behavior;
    }
}

class BasicCameraApp : public PhoneCameraApp {
public:
    explicit BasicCameraApp(ShareBehavior* behavior):
        PhoneCameraApp(behavior) { }

    void edit() override {
        std::cout << "Photo edited using basic features of the app.\n";
    }
};

class CameraPlusApp : public PhoneCameraApp {
public:
    explicit CameraPlusApp(ShareBehavior* behavior):
        PhoneCameraApp(behavior) { }

    void edit() override {
        std::cout << "Photo edited using the advanced features of the premium app.\n";
    }

};



