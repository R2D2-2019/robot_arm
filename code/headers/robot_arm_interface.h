//
// Created by BroBeans on 19-3-2019.
//

#pragma once
#include "hwlib.hpp"


namespace R2D2::robot_arm_interface {
    template<typename T>
    class robot_arm_interface {
    public:
        void move_head_to_coordinate(const uint8_t &x, const uint8_t &y, const uint8_t &z) {
            static_cast<T *>(this)->move_head_to_coordinate_impl(x, y, z);
        }

        void rotate_head(const uint8_t &r) {
            static_cast<T *>(this)->rotate_head_impl(r);
        }

    private:

        void move_head_to_coordinate_impl(const uint8_t &x, const uint8_t &y, const uint8_t &z) {
            // Default implementation
        }

        void rotate_head_impl(const uint8_t &r) {
            // Default implementation
        }
    };
}