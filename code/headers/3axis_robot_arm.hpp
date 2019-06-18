#pragma once

#include "robot_arm_interface.hpp"
#include "vector3.h"

namespace r2d2::robot_arm {
    /**
     * class to controll robot arms wich has 3 axis and 2 joint and are
     * controled with a servo.
     */

    class 3axis_robot_arm_c : public robot_arm_interface_c {
    private:
        vector3i_c location_end_effector;

    public:
        /**
         * 3 axis Robot arm constructor
         */
        3axis_robot_arm_c();
        /**
         * This function moves the robot arm head to a certain 3d location.
         *
         * @param coordinate
         */
        void move_head_to_coordinate(const vector3i_c &coordinate);
        /**
         * This function rotates the head of the robot arm to grab objects.
         *
         * @return
         */
        vector3i_c get_location_end_effector();
        /**
         * This function rotates the head of the robot arm to grab objects.
         *
         * @param rotation degrees of ratations of the head
         */
        void rotate_head(const int16_t &rotation);
    };
} // namespace r2d2::robot_arm
