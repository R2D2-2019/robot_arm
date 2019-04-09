#include "gcode_generator_c.hpp"

namespace r2d2::robot_arm {

    class uArm_gcode_generator_c : public gcode_generator_c {
    public:
        /**
         * Constructor to construct a buffer array.
         * Initializes buffer with '\0'
         * 
         * @param char *buffer
         * */
        uArm_gcode_generator_c(char *buffer);
        /**
         * Default constructor
         * */
        uArm_gcode_generator_c() = default;

        /**
         * Default destructor
         * */
        ~uArm_gcode_generator_c() = default;

        /**
         * Converts a vector3i_c to a gcode command for uArm
         * 
         * @param vector3i
         * @param uint8_t speed
         * @return char* to buffer
         * */
        char *coordinate_to_gcode(const vector3i_c &coordinate,
                                  const uint8_t &speed) const override;
    };
} // namespace r2d2::robot_arm