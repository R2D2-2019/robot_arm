#include "dof4_diy_c.hpp"
#include "robot_arm_interface_c.hpp"
#include "uarm_swift_pro_c.hpp"
#include <hwlib.hpp>

using namespace r2d2::robot_arm;

int main() {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
}