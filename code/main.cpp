#include "hwlib.hpp"
#include "test_arm.h"
#include "headers/robot_arm_interface.h"
#include "headers/test_arm.h"


int main(void) {
  // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    r2d2::robot_arm::robot_arm_interface<r2d2::robot_arm::test_arm> testArm;
    testArm.move_head_to_coordinate(1,2,3);

    r2d2::robot_arm::robot_arm_interface<r2d2::robot_arm::test_arm> testArm2;
    testArm2.rotate_head(4);

//    for (;;){
//        hwlib::cout << "this works via arduino";
//        hwlib::wait_ms(1000);
//    }
}