#include "hwlib.hpp"
#include "robot_arm.hpp"
#include "robot_arm_interface_c.h"
#include "test_arm_c.h"
#include "uarm_swift.hpp"

#include <hardware_usart.hpp>

int main(void) {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    // tests on hardware
    r2d2::robot_arm::robot_arm_interface_c<r2d2::robot_arm::test_arm_c> testArm;
    testArm.move_head_to_coordinate(1, 2, 3);

    ////tests on hardware
    r2d2::robot_arm::robot_arm_interface_c<r2d2::robot_arm::test_arm_c>
        testArm2;
    testArm2.rotate_head(4);

    r2d2::uart_ports_c port_one = r2d2::uart_ports_c::uart1;
    auto uarm = r2d2::robot_arm::uarm_swift_c(115200, port_one);

    uarm.send_command("#n M17\n");
    uarm.send_command("#n M2122 V1\n");

    while (1) {
        uarm.move_head_to_coordinate({320, 100, 120}, 4000);
        uarm.move_head_to_coordinate({320, 100, 20}, 4000);
        uarm.move_head_to_coordinate({80, 80, 50}, 6000);
    }
}