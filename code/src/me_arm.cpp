#include "me_arm.hpp"
#include "servo.hpp"
#include "vector3.hpp"
#include "hwlib.hpp"
#include <cmath>




namespace r2d2::robot_arm {

me_arm_c::me_arm_c(servo_c servo1, servo_c servo2, servo_c servo3, calculate_inverse_kinematics_c &calculator):
    servo1(servo1),
    servo2(servo2),
    servo3(servo3),
    calculator(calculator)
{
    servo1.servo_rotate(180,r2d2::robot_arm::angles::theta),
    servo2.servo_rotate(180, r2d2::robot_arm::angles::beta),
    servo3.servo_rotate(100, r2d2::robot_arm::angles::theta);
    hwlib::wait_ms(100); 
}

void me_arm_c::move_head_to_coordinate(const vector3i_c &coordinate){
    calculator.set_position_end_effector(coordinate);    

    float theta = calculator.get_angle_theta();
    float beta = calculator.get_angle_beta();
    uint16_t gamma = coordinate.z;

    theta += 30;

    beta = int(theta) - (int(90-int(beta)));

    servo1.servo_rotate(int(theta), r2d2::robot_arm::angles::theta);
    servo2.servo_rotate(int(beta), r2d2::robot_arm::angles::beta);

    if(gamma < 0){
        gamma *= -1;
        servo3.servo_rotate(gamma, r2d2::robot_arm::angles::beta);
    } else {
        servo3.servo_rotate(gamma, r2d2::robot_arm::angles::theta);
    }

}


void me_arm_c::move_head_to_coordinate(const vector3i_c &coordinate, uint16_t speed){
    move_head_to_coordinate(coordinate);
    //The me arm servo's do not have a variable speed. 
    //A diffrent speed could be implemented by using steps but for that the steps have to be calculated first.
    hwlib::cout << "speed is not implemented" << "\n";
}

void me_arm_c::rotate_head(int16_t rotation){
    //The me arm does not have a rotating head.
    hwlib::cout << "Me arm does not have a rotating head\n";
}


}//end namespace r2d2::robot_arm