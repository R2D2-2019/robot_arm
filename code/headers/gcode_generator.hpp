#pragma once
#include "coordinate_3D_c.hpp"
#include <algorithm> //std::swap
#include <cstring>
#include <stdint.h> //uint

namespace r2d2::robot_arm {
    /**
     * Interface for generating gcodes.
     * Has a few helper functions such as converting an int to a char.
     * */

    class gcode_generator {
    private:
        void reverse(char *string, uint8_t length) const;

    public:
        /**
         * Default constructor
         * */
        gcode_generator() = default;

        /**
         * Default destructor
         * */
        virtual ~gcode_generator() = default;

        /**
         * Converts an int to a string.
         * Please note that the destination size must be 11 if you
         * want to store a max integer value (2.147.483.647) + '\0' = 11
         *
         * @param int axis
         * @param char array
         * @return char* to destination
         * */
        char *int_to_string(int axis, char *destination) const;

        char *append(char *destination, const char *source);
        /**
         * Pure virtual function for gcode command.
         * Every robot arm might have different gcode commands.
         *
         * @param coordinate_3D_c
         * @char char array
         * @return char* to destination
         * */
        virtual char *coordinate_to_gcode(const coordinate_3D_c &coordinate,
                                          char *destination) const = 0;
    };
} // namespace r2d2::robot_arm