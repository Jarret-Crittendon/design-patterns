#include "PhoneCameraApp.hpp"

int main() {
    BasicCameraApp bc(email);
    CameraPlusApp cp(social_media);

    bc.take();
    bc.save();
    bc.perform_share();
    bc.set_share(none);

    std::cout << "\n\n";

    cp.take();
    cp.save();
    cp.perform_share();
    cp.set_share(text);
    cp.perform_share();
}