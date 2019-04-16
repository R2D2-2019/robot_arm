#pragma once

#include "vector3_c.hpp"
#include <hwlib.hpp>

/**
 * Class robot_arm_interface provides the interface for different robot arms.
 */
namespace r2d2::robot_arm{
     class robot_arm_interface_c{

     public:

         /**
         * This function moves the robot arm head to a certain 3d location.
         *
         * @param coordinate
         */
         virtual void move_head_to_coordinate(const vector3i_c &coordinate) = 0;


         /**
         * This function rotates the head of the robot arm.
         *
         * @param rotation
         */
         virtual void rotate_head(const int16_t &rotation) =0;

     };
};