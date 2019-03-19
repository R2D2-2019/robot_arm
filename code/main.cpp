#include "hwlib.hpp"
#include "src/test_arm.h"
#include "src/robot_arm_interface.h"


int main(void) {
  // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    robot_arm_interface<test_arm> temp;
    temp.move_head_to_coordinate(1,2,3);

//    for (;;){
//        hwlib::cout << "this works via arduino";
//        hwlib::wait_ms(1000);
//    }
}