#pragma once
#include "vector3.hpp"
#include <hwlib.hpp>

namespace r2d2::robot_arm {

    struct data_point{
        vector3i_c coordinate;
        uint16_t direction[2];
    public:
        data_point(vector3i_c coordinate, uint16_t direction_m[2]):
            coordinate(coordinate)
        {
            direction[0] = direction_m[0];
            direction[1] = direction_m[1];
        };
    };

    class calculate_position_kinematics_c {
    private:
        uint16_t array_se[2] = {85, 115};
        uint16_t array_sw[2] = {140, 180};
        uint16_t array_nw[2] = {85, 180};
        data_point south_east = data_point(vector3i_c(0, 0, 0), {0});
        data_point south_west = data_point(vector3i_c(215, 0, 0), array_sw);
        // data_point north_east = data_point(vector3i_c(0, 0, 0), 0);
        data_point north_west = data_point(vector3i_c(145, 190, 0), array_nw);

    public:
        calculate_position_kinematics_c();
        /**
         * @brief
         * This function calculates the angles of the robot arm when a
         *position is given.
         *
         *@param coordinate to move
         *@param arm_values uint16_t the array with pwm values for the servo.
         *
         */
        void calculate_robot_arm_value(vector3i_c coordinate_end_point,
                                       uint16_t arm_values[]);
    };
} // namespace r2d2::robot_arm
