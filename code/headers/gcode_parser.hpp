#pragma once
#include "coordinate_3D_c.hpp"
#include "hwlib.hpp"

namespace r2d2::robot_arm {

    class gcode_parser {
    private:
    public:
        gcode_parser() = default;
        ~gcode_parser() = default;

        template<size_t Size>
        virtual const char *coordinate_to_string(const coordinate_3D_c &coordinate) = 0;
    };
} // namespace r2d2::robot_arm