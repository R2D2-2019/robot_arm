#pragma once

#include <hwlib.hpp>
#include "robot_arm_interface_c.hpp"
#include "vector3_c.hpp"

/**
 * Class dof4_diy_c provides a implementation for 4dof_diy robot arm.
 */
namespace r2d2::robot_arm{
    class dof4_diy : public robot_arm_interface{
    public:

        /**
         * This function moves the 4Dof diy head to a certain 3d location.
         *
         * @param coordinate
         */
        void move_head_to_coordinate(const vector3i_c &coordinate) override;

        /**
        * This function rotates the head of the 4dof diy robot arm.
        *
        * @param rotation
        */
        void rotate_head(const int16_t &rotation) override;

    };
}
