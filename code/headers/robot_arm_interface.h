//
// Created by BroBeans on 19-3-2019.
//

#pragma once
#include "hwlib.hpp"


namespace r2d2::robot_arm {
    template<typename T>
    class robot_arm_interface {
    public:
        void move_head_to_coordinate(const uint16_t &x, const uint16_t &y, const uint16_t &z) {
            static_cast<T *>(this)->move_head_to_coordinate_impl(x, y, z);
        }

        void rotate_head(const uint16_t &r) {
            static_cast<T *>(this)->rotate_head_impl(r);
        }

    private:

     //   bool in_range(const uint16_t &x, const uint16_t &y, const uint16_t &z);

        void move_head_to_coordinate_impl(const uint16_t &x, const uint16_t &y, const uint16_t &z) {
            // Default implementation
        }

        void rotate_head_impl(const uint16_t &r) {
            // Default implementation
        }
    };
}