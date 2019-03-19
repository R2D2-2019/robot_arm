//
// Created by BroBeans on 19-3-2019.
//

#pragma once
#include "hwlib.hpp"



template<typename T>
class robot_arm_interface {
public:
     void move_head_to_coordinate(const int x, const int y, const int z) {
        static_cast<T*>(this)->move_head_to_coordinate_impl(x, y, z);
    }
private:
    const void move_head_to_coordinate_impl(const int x, const int y, const int z) {
        // Default implementation
    }
};