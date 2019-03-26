#include "hwlib.hpp"
#include "test_arm_c.h"
#include "robot_arm_interface_c.h"
#include "test_arm_c.h"


int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);


    //tests on hardware
    r2d2::robot_arm::robot_arm_interface_c<r2d2::robot_arm::test_arm_c> testArm;
    testArm.move_head_to_coordinate( 1, 2, 3);

    ////tests on hardware
    r2d2::robot_arm::robot_arm_interface_c<r2d2::robot_arm::test_arm_c> testArm2;
    testArm2.rotate_head(4);
}