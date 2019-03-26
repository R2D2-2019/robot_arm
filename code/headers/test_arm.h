//
// Created by BroBeans on 19-3-2019.
//
#pragma once

#include "../headers/robot_arm_interface.h"
#include "hwlib.hpp"

namespace r2d2::robot_arm {
class test_arm : public r2d2::robot_arm::robot_arm_interface<test_arm> {


    public:
        void move_head_to_coordinate_impl(const uint16_t &x, const uint16_t &y, const uint16_t &z);

        void rotate_head_impl(const uint16_t &r);

    private:




        const uint16_t max_range_x = 3000;
        const uint16_t min_range_x = 0;

        const uint16_t max_range_y = 4000;
        const uint16_t min_range_y = 0;

        const uint16_t max_range_z = 5000;
        const uint16_t min_range_z = 0;

        const uint16_t max_rotation_degrees = 180;
        const uint16_t min_rotation_degrees = 0;

    };
}