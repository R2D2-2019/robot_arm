#pragma once

#include <hwlib.hpp>
#include "robot_arm_interface_c.hpp"
#include "vector3_c.hpp"

/**
 * Class uArm_swift_pro provides a implementation for uArm swift pro.
 */
namespace r2d2::robot_arm{
    class uArm_swift_pro_c : public robot_arm_interface{
    public:

        /**
         * This function moves the uArm swift pro head to a certain 3d location.
         *
         * @param v
         */
        void move_head_to_coordinate( const vector3i_c &coordinate) override;
        /**
        * This function rotates the head of the 4dof diy robot arm.
        *
        * @param r
        */
        void rotate_head(const int16_t &rotation) override;

    };
}
