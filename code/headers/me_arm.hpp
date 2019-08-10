#pragma once

#include "calculate_inverse_kinematics.hpp"
#include "robot_arm_interface.hpp"
#include "servo.hpp"
#include "vector3.hpp"
namespace r2d2::robot_arm {
    /**
     * class to controll robot arms wich has 3 axis and 2 joint and are
     * controled with a servo.
     */

    class me_arm_c : public robot_arm_interface_c {
    private:
        vector3i_c location_end_effector;
        servo_c servo1, servo2, servo3;
        calculate_inverse_kinematics_c &calculator;

    public:
        /**
         * 3 axis Robot arm constructor
         */
        me_arm_c(servo_c servo1, servo_c servo2, servo_c servo3, calculate_inverse_kinematics_c &calculator);

        /**
         * This function moves the robot arm head to a certain 3d location.
         *
         * @param coordinate
         */
        void move_head_to_coordinate(const vector3i_c &coordinate) override;



        void move_head_to_coordinate(const vector3i_c &coordinate,
                                             uint16_t speed) override;
        /**
         * This function rotates the head of the robot arm to grab objects.
         *
         * @return
         */
        // vector3i_c get_location_end_effector();
        /**
         * This function rotates the head of the robot arm to grab objects.
         *
         * @param rotation degrees of ratations of the head
         */
        void rotate_head(int16_t rotation) override;
        // void rotate_head(const int16_t &rotation) override;
    };
} // namespace r2d2::robot_arm
