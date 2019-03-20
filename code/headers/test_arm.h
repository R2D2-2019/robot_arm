//
// Created by BroBeans on 19-3-2019.
//
#pragma once

#include "robot_arm_interface.h"
#include "hwlib.hpp"

namespace R2D2::robot_arm_interface {
    class test_arm : public robot_arm_interface<test_arm> {


    public:
        void move_head_to_coordinate_impl(const uint8_t &x, const uint8_t &y, const uint8_t &z) {
            //implementation
            hwlib::cout << " " << x << y << z;
        }

        void rotate_head_impl(const uint8_t &r) {
            // Default implementation
            hwlib::cout << " " << r;
        }

    private:

        uint8_t max_range_x = 3000;
        uint8_t min_range_x = 0;

        uint8_t max_range_y = 4000;
        uint8_t min_range_y = 0;

        uint8_t max_range_z = 5000;
        uint8_t min_range_z = 0;

        uint8_t max_rotation_degrees = 180;
        uint8_t min_rotation_degrees = 0;

    };
}