#include <calculate_inverse_kinematics.hpp>
#include <hardware_usart.hpp>
#include <hwlib.hpp>
#include <servo.hpp>
#include <snam_arm.hpp>
#include <uarm_swift_pro.hpp>
#include <vector3.hpp>

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    //_______________uarm__________________________
    auto usart = r2d2::usart::hardware_usart_c<r2d2::usart::usart0>(115200);
    r2d2::robot_arm::uarm_swift_pro_c uarm(usart);

    // driver code
    uarm.init();
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(100, 100, 100));
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(25, 175, 100),
                                 500);
    // You can add an extra parameter after the vector for speed if you'd like
    // i.e. uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i(100, 100,
    // 100), 500);

    //__________________snam_arm_________________________
    auto servo1 = r2d2::robot_arm::servo_c(0); // servo for the first joint.
    auto servo2 = r2d2::robot_arm::servo_c(1); // servo for the second joint.
    auto servo3 = r2d2::robot_arm::servo_c(
        2, r2d2::pwm_lib::clocks::CLOCKB);     // servo for the direction.
    auto servo4 = r2d2::robot_arm::servo_c(3); // servo for rotating the head.

    r2d2::robot_arm::calculate_inverse_kinematics_c calculator =
        r2d2::robot_arm::calculate_inverse_kinematics_c(
            100, 190); // 100 is the length of the bottom arm in mm, 190 is the
                       // length of the top arm in mm

    auto snam_arm =
        r2d2::robot_arm::snam_arm_c(servo1, servo2, servo3, servo4, calculator);

    snam_arm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(150, 200, 135),
                                     10);

    return 0;
}
