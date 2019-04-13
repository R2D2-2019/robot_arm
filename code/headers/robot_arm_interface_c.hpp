//
// Created by Slimmerik on 13/04/2019.
//

#pragma once

#include <vector3_c.hpp>
#include <hwlib.hpp>

namespace r2d2::robot_arm{
     class robot_arm_interface{

     public:
         // pure virtual function providing interface framework.
         virtual void move_head_to_coordinate(const vector3_c< uint16_t > &v) = 0;

         virtual void rotate_head(const uint16_t &r) =0;

     protected:

     };
};