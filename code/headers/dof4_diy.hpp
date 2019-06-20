#pragma once

#include <cstdint> // size_t, (u)intx_t
#include <robot_arm_interface.hpp>
#include <vector3.hpp>

/**
 * Class dof4_diy_c provides a implementation for 4dof_diy robot arm.
 */
namespace r2d2::robot_arm {
    class dof4_diy_c : public robot_arm_interface_c {
    public:
        /**
         * @brief
         * This function moves the 4Dof diy head to a certain 3d location.
         *
         * @param coordinate the coordinate the head needs to move to
         */
        void move_head_to_coordinate(const vector3i_c &coordinate) override;

        /**
         * @brief
         * This function moves the robot arm head to a certain 3d location
         * at a given speed.
         *
         * @param coordinate The coordinate the head needs to move to
         * @param speed The speed the head moves at
         */
        void move_head_to_coordinate(const vector3i_c &coordinate,
                                     uint16_t speed) override;
        /**
         * @brief
         * This function rotates the head of the 4dof diy robot arm.
         *
         * @param rotation The rotation value the head needs to move
         */
        void rotate_head(int16_t rotation) override;
    };
} // namespace r2d2::robot_arm
