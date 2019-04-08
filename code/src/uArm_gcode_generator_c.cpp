#include "uArm_gcode_generator_c.hpp"
#include <iostream>
namespace r2d2::robot_arm {
    char *
    uArm_gcode_generator_c::coordinate_to_gcode(const vector3i_c &coordinate, char *destination, const uint8_t &speed) const {
        char x_string[11]; //max number of int digits (10) + '\0' = 11
        char y_string[11];
        char z_string[11];
        char speed_string[11];
        int_to_string(coordinate.x, x_string);
        int_to_string(coordinate.y, y_string);
        int_to_string(coordinate.z, z_string);
        int_to_string(speed, speed_string);
        append(destination, "#n G0 X");
        append(destination, x_string);
        append(destination, " Y");
        append(destination, y_string);
        append(destination, " Z");
        append(destination, z_string);
        append(destination, " F");
        append(destination, speed_string);
        append(destination, "\n");
        return destination;
    }
} // namespace r2d2::robot_arm