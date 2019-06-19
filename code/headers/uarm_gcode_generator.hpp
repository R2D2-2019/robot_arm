#include <gcode_generator.hpp>
#include <cstdint>

namespace r2d2::robot_arm {
    template <size_t Size>
    class uarm_gcode_generator_c : public gcode_generator_c<Size> {
    public:
        /**
         * Converts a vector3i_c to a gcode command for uArm
         *
         * @param vector3i
         * @param uint8_t speed
         * */
        void coordinate_to_gcode(const vector3i_c &coordinate,
                                 const uint16_t &speed) {
            char x_string[11]; // max number of int digits (10) + '\0' = 11
            char y_string[11];
            char z_string[11];
            char speed_string[11];
            this->int_to_string(coordinate.x, x_string);
            this->int_to_string(coordinate.y, y_string);
            this->int_to_string(coordinate.z, z_string);
            this->int_to_string(speed, speed_string);
            this->append("#n G0 X");
            this->append(x_string);
            this->append(" Y");
            this->append(y_string);
            this->append(" Z");
            this->append(z_string);
            this->append(" F");
            this->append(speed_string);
            this->append("\n");
        }
    };
} // namespace r2d2::robot_arm