#include <cmath>
#include <hwlib.hpp>
#include <me_arm.hpp>
#include <servo.hpp>
#include <vector3.hpp>

namespace r2d2::robot_arm {

    me_arm_c::me_arm_c(servo_c servo1, servo_c servo2, servo_c servo3,
                       calculate_inverse_kinematics_c &calculator)
        : servo1(servo1),
          servo2(servo2),
          servo3(servo3),
          calculator(calculator) {
        // set arm at start position. set servo1, servo2 and servo3 at 90
        // degrees.
        uint16_t start_position = 90;
        servo1.servo_rotate(start_position, r2d2::robot_arm::angles::theta),
            servo2.servo_rotate(start_position, r2d2::robot_arm::angles::beta),
            servo3.servo_rotate(start_position, r2d2::robot_arm::angles::theta);
        hwlib::wait_ms(100);
    }

    void me_arm_c::move_head_to_coordinate(const vector3i_c &coordinate) {
        // calculate the angles in degrees for servo1 and servo2
        calculator.set_position_end_effector(coordinate);

        // get the angles in degrees for servo1 and servo2
        float theta = calculator.get_angle_theta();
        float beta = calculator.get_angle_beta();

        // get the angle in degrees for servo3
        uint16_t gamma = coordinate.z;

        // fix the offset of theta/servo1.
        theta += 30;

        // beta has to have a 90 degree offset in correspondence of theta.
        beta = static_cast<int>(theta) -
               (static_cast<int>(90 - static_cast<int>(beta)));

        // set the position of servo1 and servo2
        servo1.servo_rotate(static_cast<int>(theta),
                            r2d2::robot_arm::angles::theta);
        servo2.servo_rotate(static_cast<int>(beta),
                            r2d2::robot_arm::angles::beta);

        // set the position of servo1 and servo2
        if (gamma < 0) {
            gamma *= -1;
            servo3.servo_rotate(gamma, r2d2::robot_arm::angles::beta);
        } else {
            servo3.servo_rotate(gamma, r2d2::robot_arm::angles::theta);
        }
    }

    void me_arm_c::move_head_to_coordinate(const vector3i_c &coordinate,
                                           uint16_t speed) {
        // defines.
        uint16_t max_speed = 1000;
        uint16_t degrees_per_speed = 90;
        uint16_t step_sleep_ms = 1;

        // cap max speed.
        if (speed > max_speed) {
            speed = max_speed;
        }

        // calculate the angles for servo1 and servo2
        calculator.set_position_end_effector(coordinate);

        // get the calculated angles for servo1 and servo2
        float theta = calculator.get_angle_theta();
        float beta = calculator.get_angle_beta();

        // get the angle for servo3
        r2d2::robot_arm::angles gamma_angle = servo3.get_last_angle();

        // get the angle in degrees for servo3
        uint16_t gamma = coordinate.z;

        // initalise variables.
        float step = 0;
        float beta_rotation = 0;
        float theta_rotation = 0;
        float gamma_rotation = 0;
        bool beta_up = true;
        bool theta_up = true;
        bool gamma_up = true;

        // fix the offset of theta/servo1.
        theta += 30;

        // beta has to have a 90 degree offset in correspondence of theta.
        beta = static_cast<int>(theta) -
               (static_cast<int>(90 - static_cast<int>(beta)));

        // set the correct angle for servo 3
        if (gamma < 0) {
            gamma *= -1;
            gamma_angle = r2d2::robot_arm::angles::beta;
        } else {
            gamma_angle = r2d2::robot_arm::angles::theta;
        }

        // get rotation angles and directions per servo
        if (servo1.get_last_degree() < theta) {
            theta_up = true;
            theta_rotation = theta - servo1.get_last_degree();
        } else {
            theta_up = false;
            theta_rotation = servo1.get_last_degree() - theta;
        }

        if (servo2.get_last_degree() < beta) {
            beta_up = true;
            beta_rotation = beta - servo2.get_last_degree();
        } else {
            beta_up = false;
            beta_rotation = servo2.get_last_degree() - beta;
        }

        if (servo3.get_last_degree() < gamma) {
            gamma_up = true;
            gamma_rotation = gamma - servo3.get_last_degree();
        } else {
            gamma_up = false;
            gamma_rotation = servo3.get_last_degree() - gamma;
        }

        // find biggest angle of rotation
        float biggest_rotation = theta_rotation;
        if (biggest_rotation < beta_rotation) {
            biggest_rotation = beta_rotation;
        }
        if (biggest_rotation < gamma_rotation) {
            biggest_rotation = gamma_rotation;
        }

        // invert speed.
        speed = max_speed - speed;

        // get the step size.
        step = static_cast<float>(degrees_per_speed) / static_cast<float>(speed);

        // move servo's.
        while (biggest_rotation > 0) {
            if (theta_rotation > 0) {
                theta_rotation -= step;
                if (theta_up) {
                    servo1.servo_rotate((theta - theta_rotation),
                                        r2d2::robot_arm::angles::theta);
                } else {
                    servo1.servo_rotate((theta_rotation + theta),
                                        r2d2::robot_arm::angles::theta);
                }
            }
            if (beta_rotation > 0) {
                beta_rotation -= step;
                if (beta_up) {
                    servo2.servo_rotate((beta - beta_rotation),
                                        r2d2::robot_arm::angles::beta);
                } else {
                    servo2.servo_rotate((beta_rotation + beta),
                                        r2d2::robot_arm::angles::beta);
                }
            }
            if (gamma_rotation > 0) {
                gamma_rotation -= step;
                if (gamma_up) {
                    servo3.servo_rotate((gamma - gamma_rotation), gamma_angle);
                } else {
                    servo3.servo_rotate((gamma_rotation + gamma), gamma_angle);
                }
            }
            biggest_rotation -= step;
            hwlib::wait_ms(step_sleep_ms);
        }

        // make sure the servo's are at the final angle.
        servo1.servo_rotate(theta, r2d2::robot_arm::angles::theta);
        servo2.servo_rotate(beta, r2d2::robot_arm::angles::beta);
        servo3.servo_rotate(gamma, gamma_angle);
    }

    void me_arm_c::rotate_head(int16_t rotation) {
        // The me arm does not have a rotating head.
        hwlib::cout << "Me arm does not have a rotating head\n";
    }

} // end namespace r2d2::robot_arm