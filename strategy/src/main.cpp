#include "PhoneCameraApp.hpp"

int main() {
    BasicCameraApp bc(new Email);
    CameraPlusApp cp(new Social_Media);

    bc.take();
    bc.save();
    bc.perform_share();

    std::cout << "\n\n";

    cp.take();
    cp.save();
    cp.perform_share();
    cp.set_share(new Text);
    cp.perform_share();
}