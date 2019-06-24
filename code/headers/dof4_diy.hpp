#pragma once

#include <hwlib.hpp>
#include <robot_arm_interface.hpp>
#include <vector3.hpp>


/**
 * Class dof4_diy_c provides a implementation for 4dof_diy robot arm.
 */
namespace r2d2::robot_arm {
    class dof4_diy_c : public robot_arm_interface_c {
    public:
        /**
         * This function moves the 4Dof diy head to a certain 3d location.
         *
         * @param coordinate
         */
        void move_head_to_coordinate(const vector3i_c &coordinate) override;

        /**
         * This function moves the robot arm head to a certain 3d location
         * at a given speed.
         *
         * @param coordinate
         * @param speed
         */
        void move_head_to_coordinate(const vector3i_c &coordinate,
                                     const uint16_t &speed) override;
    };
} // namespace r2d2::robot_arm
