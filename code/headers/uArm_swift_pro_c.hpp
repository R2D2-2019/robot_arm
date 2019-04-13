//
// Created by Slimmerik on 13/04/2019.
//
#pragma once

#include <hwlib.hpp>
#include <robot_arm_interface_c.hpp>
#include <vector3_c.hpp>

namespace r2d2::robot_arm{
    class uArm_swift_pro : public robot_arm_interface{



        void move_head_to_coordinate(const vector3_c< uint16_t > &v);



        void rotate_head(const uint16_t &r);


    };


}
