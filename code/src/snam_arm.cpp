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
        //1000 is max speed
        if(speed > 1000){
            speed = 1000;
        }

        calculator.set_position_end_effector(coordinate);

        float theta = calculator.get_angle_theta();
        float beta = calculator.get_angle_beta();
        float step = 0;
        r2d2::robot_arm::angles gamma_angle = servo3.get_last_angle();
        uint16_t gamma = coordinate.z;

        float beta_rotation = 0;
        float theta_rotation = 0;
        float gamma_rotation = 0;
        bool beta_up = true;
        bool theta_up = true;
        bool gamma_up = true;

        r2d2::robot_arm::angles beta_angle = r2d2::robot_arm::angles::beta;
        r2d2::robot_arm::angles theta_angle = r2d2::robot_arm::angles::theta;

        beta -= 90 - theta;

        if (beta < 0) {
            beta_angle = r2d2::robot_arm::angles::theta;
            beta *= -1;
        }
        if (theta < 0) {
            theta_angle = r2d2::robot_arm::angles::beta;
            theta *= -1;
        }

        beta = round(beta);
        theta = round(theta);

        if(gamma < 0){
        gamma *= -1;
        gamma_angle = r2d2::robot_arm::angles::beta;
    } else {
        gamma_angle = r2d2::robot_arm::angles::theta;
    }


    if(servo1.get_last_degree() < theta){
        theta_up = true;
        theta_rotation = theta - servo1.get_last_degree();
    } else {
        theta_up = false;
        theta_rotation = servo1.get_last_degree()- theta;
    }

    
    if(servo2.get_last_degree() < beta){
        beta_up = true;
        beta_rotation = beta - servo2.get_last_degree();
    } else {
        beta_up = false;
        beta_rotation = servo2.get_last_degree() - beta;
    }

    if(servo3.get_last_degree() < gamma){
        gamma_up = true;
        gamma_rotation = gamma - servo3.get_last_degree();
    } else {
        gamma_up = false;
        gamma_rotation = servo3.get_last_degree() - gamma;
    }
    
    float biggest_rotation = theta_rotation;
    if(biggest_rotation < beta_rotation){
        biggest_rotation = beta_rotation;
    }
    if(biggest_rotation < gamma_rotation){
        biggest_rotation = gamma_rotation;
    }
    
    speed = 1000 - speed;
    //step size per 90 degrees.
    step = float(90)/float(speed);


    while(biggest_rotation > 0){
        if(theta_rotation > 0){
            theta_rotation -= step;
            if(theta_up){
                servo1.servo_rotate((theta-theta_rotation), r2d2::robot_arm::angles::theta);
            } else {
                servo1.servo_rotate((theta_rotation+theta), r2d2::robot_arm::angles::theta);
            }
        }
        if(beta_rotation > 0){
            beta_rotation -= step;
            if(beta_up){
                servo2.servo_rotate((beta-beta_rotation), r2d2::robot_arm::angles::beta);
            } else {
                servo2.servo_rotate((beta_rotation+beta), r2d2::robot_arm::angles::beta);
            }
        }
        if(gamma_rotation > 0){
            gamma_rotation -= step;
            if(gamma_up){
                servo3.servo_rotate((gamma-gamma_rotation), gamma_angle);
            } else {
                servo3.servo_rotate((gamma_rotation+gamma), gamma_angle);
            }
        }
        biggest_rotation -= step;
        hwlib::wait_ms(1);
    }

    servo1.servo_rotate(theta, theta_angle);
    servo2.servo_rotate(beta, beta_angle);
    servo3.servo_rotate(gamma, gamma_angle);
    }

    void snam_arm_c::rotate_head(int16_t rotation) {
        servo4.servo_rotate(rotation, r2d2::robot_arm::angles::theta);
    }

} // end namespace r2d2::robot_arm