/**
 * Class robot_arm provides a test implementation for a robot arm.
 */
#pragma once

#include <../headers/robot_arm_interface_c.hpp>
#include <hwlib.hpp>

namespace r2d2::robot_arm {
    class test_arm_c : public robot_arm_interface_c<test_arm_c> {
    public:

        /**
         * This function moves the robot arm to a certain 3d location.
         *
         * @param x
         * @param y
         * @param z
         * @return bool
         */
        void move_head_to_coordinate_impl(const int16_t &x, const int16_t &y, const int16_t &z);


        /**
         * This function rotates the head of the robot arm.
         *
         * @param x
         * @param y
         * @param z
         * @return bool
         */
        void rotate_head_impl(const uint16_t &r);

    private:

        /**
         * This function checks if parameters are in range of min and max range of robot arm.
         *
         * @param x
         * @param y
         * @param z
         * @return bool
         */
        bool in_range(const int16_t &x, const int16_t &y, const int16_t &z);

        /**
         * This function checks if parameters are in range of min and max range of robot arm.
         *
         * @param r
         * @return bool
         */
        bool in_range(const uint16_t &r);

        //TODO probably doesnt work with mulitple robot arm implementations
        const static int16_t max_range_x = 10;
        const static int16_t min_range_x = 0;

        const static int16_t max_range_y = 20;
        const static int16_t min_range_y = 0;

        const static int16_t max_range_z = 30;
        const static int16_t min_range_z = 0;

        const static uint16_t max_rotation_degrees = 180;
        const static uint16_t min_rotation_degrees = 0;
    };
}