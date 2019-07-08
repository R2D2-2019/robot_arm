#include <calculate_position_kinematics.hpp>

namespace r2d2::robot_arm {

    calculate_position_kinematics_c::calculate_position_kinematics_c(){};

    void calculate_position_kinematics_c::calculate_robot_arm_value(
        vector3i_c coordinate_end_point, uint16_t arm_values[]) {
        uint16_t servo_value_SE;
        uint16_t servo_value_SW;
        uint16_t servo_value_NW;

        uint16_t x_as_servo_value_bottom = 0;
        uint16_t y_as_servo_value_bottom = 0;

        for (uint16_t i = 0; i < 2; i++) {

            servo_value_SE = array_se[i];
            servo_value_SW = array_sw[i];
            servo_value_NW = array_sw[i];

            uint16_t distance_difference_SE_x_as =
                coordinate_end_point.x - south_east.coordinate.x;
            uint16_t distance_difference_SW_x_as =
                coordinate_end_point.x - south_west.coordinate.x;

            x_as_servo_value_bottom =
                distance_difference_SE_x_as * servo_value_SW +
                distance_difference_SW_x_as * servo_value_SE /
                    (south_west.coordinate.x - south_east.coordinate.x);

            int distance_difference_NE_x_as =
                coordinate_end_point.x - north_east.coordinate.x;
            int distance_difference_NW_x_as =
                coordinate_end_point.x - north_west.coordinate.x;

            x_as_servo_value_top =
                distance_difference_NE_x_as * servo_value_NW +
                distance_difference_NW_x_as * servo_value_NE /
                    (north_east.coordinate.y - north_west.coordinate.y);

            servo_value = (x_as_servo_value_bottom *
                               (north_west.coordinate.y - coordinate.y) +
                           x_as_servo_value_top *
                               (coordinate.y - south_west.coordinate.y)) /
                          (north_west.coordinate.y - south_west.coordinate.y);

            arm_values[i] = servo_value;
        }
    }

} // namespace r2d2::robot_arm
