#include "hwlib.hpp"
#include "servo.hpp"
#include "calculate_inverse_kinematics.hpp"
#include <vector3.hpp>
#include "3axis_robot_arm.hpp"



int main() { 
  //kill the watchdog 
  WDT->WDT_MR = WDT_MR_WDDIS; 
  hwlib::wait_ms(1000); 

  auto servo1 = r2d2::robot_arm::servo_c(0); 
  auto servo2 = r2d2::robot_arm::servo_c(1); 
  auto servo3 = r2d2::robot_arm::servo_c(2, r2d2::pwm_lib::clocks::CLOCKB); 

  auto calculator = r2d2::robot_arm::calculate_inverse_kinematics_c(100, 190); 

  auto meArm = r2d2::robot_arm::axis_robot_arm_c(servo1, servo2, servo3, calculator); 
  servo3.servo_rotate(130, r2d2::robot_arm::angles::theta);

  int sleep_time = 2000;

  while (1) { 
    meArm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(150, 200, 135)); 
    hwlib::wait_ms(sleep_time); 
    meArm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(150, 40, 135)); 
    hwlib::wait_ms(sleep_time); 
    meArm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(150, 200, 135)); 
    hwlib::wait_ms(sleep_time); 
    meArm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(150, 200, 90)); 
    hwlib::wait_ms(sleep_time); 
    meArm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(150, 40, 90)); 
    hwlib::wait_ms(sleep_time); 
    meArm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(150, 200, 90)); 
    hwlib::wait_ms(sleep_time); 
  }
}