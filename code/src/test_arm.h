//
// Created by BroBeans on 19-3-2019.
//
#pragma once

#include "robot_arm_interface.h"
#include "hwlib.hpp"


class test_arm : public robot_arm_interface<test_arm> {
public:
    const void move_head_to_coordinate_impl(const int x, const int y, const int z) {
        //implementation
        hwlib::cout << " " << x << y << z;
    }
};