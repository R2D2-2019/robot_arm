/**
 * Template class for making a robot arm. this seemed to be a good way to avoid the heap an virtual table problem.
 *
 * "Static polymorphism (templates) is a better choice if the type should only change at compile-time"
 * https://stackoverflow.com/questions/1165963/c-standard-practice-virtual-interface-classes-vs-templates
 *
 */

#pragma once

#include <hwlib.hpp>


namespace r2d2::robot_arm {
    template<typename T>
    class robot_arm_interface_c {
    public:

       /**
        * This function moves the robot arm to a certain 3d location.
        * x y z parameters correlate to real world millimeters
        *
        * @param x
        * @param y
        * @param z
        * @return bool
        */
        void move_head_to_coordinate(const int16_t &x, const int16_t &y, const int16_t &z) {
            static_cast<T *>(this)->move_head_to_coordinate_impl(x, y, z);
        }

        /**
         * This function rotates the head of the robot arm.
         *
         * @param r
         * @return bool
         */
        void rotate_head(const uint16_t &r) {
            static_cast<T *>(this)->rotate_head_impl(r);
        }

    private:

        /**
         * Default implementation
         * This function moves the robot arm to a certain 3d location.
         *
         * @param x
         * @param y
         * @param z
         * @return bool
         */
        void move_head_to_coordinate_impl(const int16_t &x, const int16_t &y, const int16_t &z) {
            // Default implementation
        }


        /**
         * Default implementation
         * This function rotates the head of the robot arm.
         *
         * @param r
         * @return bool
         */
        void rotate_head_impl(const uint16_t &r) {
            // Default implementation
        }
    };
}