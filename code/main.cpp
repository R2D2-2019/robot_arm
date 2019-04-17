#include <dof4_diy.hpp>
#include <hwlib.hpp>
#include <robot_arm_interface.hpp>
#include <uarm_swift_pro.hpp>

using namespace r2d2::robot_arm;

int main() {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
}