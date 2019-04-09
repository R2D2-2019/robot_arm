#pragma once
#include "vector3_c.hpp"
#include "hwlib.hpp"
#include <cstring> //std::strcmp

namespace r2d2::robot_arm {
    /**
     * Interface for generating gcodes.
     * Has a few helper functions such as converting an int to a char.
     * */

    class gcode_generator_c {
    protected:
        /**
         * Pointer to a buffer. Default nullptr.
         * */
        char *buffer = nullptr;

        /**
         * Converts an int to a string.
         * Please note that the destination size must be 11 if you
         * want to store a max integer value (2.147.483.647) + '\0' = 11
         *
         * @param int axis
         * @param char array
         * @return char* to string
         * */
        char *int_to_string(int axis, char *string) const;
    public:
        /**
         * Default constructor
         * */
        gcode_generator_c() = default;

        /**
         * Constructor to construct a buffer array.
         * Initializes buffer with '\0'
         * 
         * @param char *buffer
         * */
        gcode_generator_c(char *buffer);

        /**
         * Default destructor
         * */
        virtual ~gcode_generator_c() = default;

        /** 
         * Returns a poiter to the buffer.
         * 
         * @return char* to buffer
         * */
        char *get_buffer();

        /**
         * Appends a string (source) at the end of the buffer (array)
         *
         * @param const char* source
         * @return char* to buffer
         * */
        char *append(const char *source) const;

        /**
         * Appends a string (source) at the front of buffer (array)
         *
         * @param const char* source
         * @preturn char* to buffer
         * */
        char *append_front(const char *source) const;

        /**
         * Pure virtual function for gcode command.
         * Every robot arm might have different gcode commands.
         *
         * 
         * @param coordinate_3D_c
         * @param uint8_t speed = 0
         * @return char* to buffer
         * */
        virtual char *coordinate_to_gcode(const vector3i_c &coordinate,
                                          const uint8_t &speed = 0) const = 0;
    };
} // namespace r2d2::robot_arm