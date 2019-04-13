#include <hwlib.hpp>
#include <robot_arm_interface_c.hpp>

using namespace r2d2::robot_arm;

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);



}