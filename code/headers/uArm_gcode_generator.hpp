#include "gcode_generator.hpp"

namespace r2d2::robot_arm {

    class uArm_gcode_generator : public gcode_generator {
    public:
        uArm_gcode_generator() = default;
        ~uArm_gcode_generator() = default;

        char *coordinate_to_gcode(const coordinate_3D_c &coordinate,
                                  char *destination) const override;
    };
} // namespace r2d2::robot_arm