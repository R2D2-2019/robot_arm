#include "hwlib.hpp"
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

    r2d2::uart_ports_c uart_port_one = r2d2::uart_ports_c::uart1;
    r2d2::hardware_usart_c usart_bus(115200, uart_port_one);

    auto uarm = r2d2::robot_arm::uarm_swift_c(usart_bus);
    uarm.move_joint(0, 50);
}