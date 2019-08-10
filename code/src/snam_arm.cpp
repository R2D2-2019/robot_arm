#include "snam_arm.hpp"
#include "hwlib.hpp"
#include "servo.hpp"
#include "vector3.hpp"
#include <cmath>

namespace r2d2::robot_arm {

    snam_arm_c::snam_arm_c(servo_c servo1, servo_c servo2, servo_c servo3,
                           servo_c servo4,
                           calculate_inverse_kinematics_c &calculator)
        : servo1(servo1),
          servo2(servo2),
          servo3(servo3),
          servo4(servo4),
          calculator(calculator) {
        servo1.servo_rotate(180, r2d2::robot_arm::angles::theta),
            servo2.servo_rotate(180, r2d2::robot_arm::angles::beta),
            servo3.servo_rotate(100, r2d2::robot_arm::angles::theta);
        hwlib::wait_ms(100);
    }

    void snam_arm_c::move_head_to_coordinate(const vector3i_c &coordinate) {
        calculator.set_position_end_effector(coordinate);

        float theta = calculator.get_angle_theta();
        float beta = calculator.get_angle_beta();
        uint16_t gamma = coordinate.z;

        r2d2::robot_arm::angles beta_rotation = r2d2::robot_arm::angles::beta;
        r2d2::robot_arm::angles theta_rotation = r2d2::robot_arm::angles::theta;

        beta -= 90 - theta;

        if (beta < 0) {
            beta_rotation = r2d2::robot_arm::angles::theta;
            beta *= -1;
        }
        if (theta < 0) {
            theta_rotation = r2d2::robot_arm::angles::beta;
            theta *= -1;
        }

        beta = round(beta);
        theta = round(theta);

        servo1.servo_rotate(theta, theta_rotation);
        servo2.servo_rotate(beta, beta_rotation);

        if (gamma < 0) {
            gamma *= -1;
            servo3.servo_rotate(gamma, r2d2::robot_arm::angles::beta);
        } else {
            servo3.servo_rotate(gamma, r2d2::robot_arm::angles::theta);
        }
    }

    void snam_arm_c::move_head_to_coordinate(const vector3i_c &coordinate,
                                             uint16_t speed) {
        move_head_to_coordinate(coordinate);
        // servo's do not have a speed setting. This could be done using steps.
        // But you would have to calculate the path the arm has to travel.
        hwlib::cout << "speed is not implemented for the snam arm"
                    << "\n";
    }

    void snam_arm_c::rotate_head(int16_t rotation) {
        servo4.servo_rotate(rotation, r2d2::robot_arm::angles::theta);
    }

} // end namespace r2d2::robot_arm