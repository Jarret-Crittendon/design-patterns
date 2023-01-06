
// Author: Jarret Crittendon
// 2023 JAN 04
// Overview:  Challenge Problem for LinkedIn Learning Course,
// "Programming Foundations: Design Patterns" - implementing the Strategy
// pattern

// Share photos by text, email, and social media
// 2023 JAN 05:  added enum to handle behavior changes,
// I thought exposing pointers and memory management was too unsafe.

#include <iostream>

enum ShareType { email, text, social_media, none };

class ShareBehavior {
public:
    ShareBehavior(ShareType stype):
        current_type(stype) { }

    virtual void share() = 0;
    
    virtual ~ShareBehavior() = default;


    ShareType type() const { return current_type; }

private:
    ShareType current_type;
};

class Email: public ShareBehavior {
public:
    Email():
        ShareBehavior(email) { }

    virtual void share() override {
        std::cout << "Photo sent to your email account.\n";
    };
};

class Text: public ShareBehavior {
public:
    Text():
        ShareBehavior(text) { }

    virtual void share() override {
        std::cout << "Photo sent via text to the indicated phone number.\n";
    };
};

class Social_Media: public ShareBehavior {
public:
    Social_Media():
        ShareBehavior(social_media) { }

    virtual void share() override {
        std::cout << "Photo posted to the indicated social media platform.\n";
    };
};

class None: public ShareBehavior {
public:
    None():
        ShareBehavior(none) { }

    virtual void share() override {
        std::cout << "Photo sharing has been disabled.\n";
    };
};

class PhoneCameraApp {
public:
    PhoneCameraApp(ShareType stype)
         { set_share(stype); }
    void take();
    virtual void edit() = 0;
    void save();
    void perform_share();
    void set_share(ShareType stype);

    virtual ~PhoneCameraApp() {
        delete share_action;
    };

protected:

    ShareBehavior* share_action = new None;
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

void PhoneCameraApp::set_share(ShareType stype) {
    if (share_action->type() != stype) {
        switch (stype) {
            case email: {
                delete share_action;
                share_action = new Email;
                break; 
            }

            case text: {
                delete share_action;
                share_action = new Text;  
                break; 
            }

            case social_media: {
                delete share_action;
                share_action = new Social_Media;  
                break; 
            }

            default: {
                delete share_action;
                share_action = new None;
                std::cout << "Sharing disabled.\n";  
                break; 
            }
        }
    }
}

class BasicCameraApp : public PhoneCameraApp {
public:
    BasicCameraApp(ShareType stype):
        PhoneCameraApp(stype) { }

    void edit() override {
        std::cout << "Photo edited using basic features of the app.\n";
    }
};

class CameraPlusApp : public PhoneCameraApp {
public:
    CameraPlusApp(ShareType stype):
        PhoneCameraApp(stype) { }

    void edit() override {
        std::cout << "Photo edited using the advanced features of the premium app.\n";
    }

};



