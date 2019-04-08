#include "uArm_gcode_generator_c.hpp"
#include <iostream>
namespace r2d2::robot_arm {
    uArm_gcode_generator_c::uArm_gcode_generator_c(char *buffer)
        : gcode_generator_c(buffer) {
    }

    char *
    uArm_gcode_generator_c::coordinate_to_gcode(const vector3i_c &coordinate,
                                                const uint8_t &speed) const {
        char x_string[11]; // max number of int digits (10) + '\0' = 11
        char y_string[11];
        char z_string[11];
        char speed_string[11];
        int_to_string(coordinate.x, x_string);
        int_to_string(coordinate.y, y_string);
        int_to_string(coordinate.z, z_string);
        int_to_string(speed, speed_string);
        append("#n G0 X");
        append(x_string);
        append(" Y");
        append(y_string);
        append(" Z");
        append(z_string);
        append(" F");
        append(speed_string);
        append("\n");
        return buffer;
    }
} // namespace r2d2::robot_arm