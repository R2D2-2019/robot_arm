#pragma once

#include "vector3.hpp"
#include <hwlib.hpp>

/**
 * Class robot_arm_interface provides the interface for different robot arms.
 */
namespace r2d2::robot_arm {
    class robot_arm_interface_c {

    public:
        /**
         * @brief
         * This function moves the robot arm head to a certain 3d location
         * at a given speed.
         *
         * @param coordinate The coordinate the head needs to move to
         * @param speed Te speed the head moves at
         */
        virtual void move_head_to_coordinate(const vector3i_c &coordinate,
                                             uint16_t speed) = 0;

        /**
         * @brief
         * This function moves the robot arm head to a certain 3d location.
         *
         * @param coordinate The coordinate the head needs to move to
         */
        virtual void move_head_to_coordinate(const vector3i_c &coordinate) = 0;

        /**
         * @brief
         * This function rotates the head of the robot arm.
         *
         * @param rotation The rotation value the head needs to move
         */
        virtual void rotate_head(int16_t rotation) = 0;
    };
}; // namespace r2d2::robot_arm