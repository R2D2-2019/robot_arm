#pragma once
#include "vector3_c.hpp"
#include <algorithm> //std::swap
#include <cstring>
#include <stdint.h> //uint

namespace r2d2::robot_arm {
    /**
     * Interface for generating gcodes.
     * Has a few helper functions such as converting an int to a char.
     * */

    class gcode_generator_c {
    protected:
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
    public:
        /**
         * Default constructor
         * */
        gcode_generator_c() = default;

        /**
         * Default destructor
         * */
        virtual ~gcode_generator_c() = default;

        /**
         * Appends a string (source) at the end of the destination (array)
         *
         * @param char[] destination
         * @param const char* source
         * @return char* to destination
         * */
        char *append(char *destination, const char *source) const;

        /**
         * Appends a string (source) at the front of destination (array)
         *
         * @param char[] destination
         * @param const char* source
         * @preturn char* to destination
         * */
        char *append_front(char *destination, const char *source) const;

        /**
         * Pure virtual function for gcode command.
         * Every robot arm might have different gcode commands.
         *
         * 
         * @param coordinate_3D_c
         * @char char array
         * @param uint8_t speed = 0
         * @return char* to destination
         * */
        virtual char *coordinate_to_gcode(const vector3i_c &coordinate,
                                          char *destination, const uint8_t &speed = 0) const = 0;
    };
} // namespace r2d2::robot_arm