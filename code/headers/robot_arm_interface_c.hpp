/**
 * Class robot_arm_interface provides the interface for different robot arms.
 */

#pragma once

#include "vector3_c.hpp"
#include <hwlib.hpp>

namespace r2d2::robot_arm{
     class robot_arm_interface{

     public:

         /**
         * This function moves the robot arm head to a certain 3d location.
         *
         * @param v
         */
         virtual void move_head_to_coordinate(const vector3i_c &vector) = 0;


         /**
         * This function rotates the head of the robot arm.
         *
         * @param r
         */
         virtual void rotate_head(const int16_t &rotation) =0;

     };
};