#pragma once
#include "vector3.hpp"
#include <hwlib.hpp> // size_t, (u)intx_t

namespace r2d2::robot_arm {
    /**
     * Template Interface class for generating gcodes.
     * Has a few helper functions such as converting an int to a char.
     * Size represents the size of the char buffer array.
     * Note that a string of 4 characters, has a size of 5 with the '\0'
     * character
     * @param Size buffer size
     * */
    template <size_t Size>
    class gcode_generator_c {
    protected:
        /**
         * Buffer with Size as size.
         * */
        char buffer[Size] = {'\0'};

        /**
         * Converts an int to a string.
         * Please note that the destination size must be 11 if you
         * want to store a max integer value (2.147.483.647) + '\0' = 11
         *
         * @param int axis
         * @param char array
         * @return char* to string
         * */
        char *int_to_string(int axis, char *string) const {
            int i = 0;
            bool is_negative = axis < 0;
            int n = is_negative ? -axis : axis;
            if (n == 0) {
                string[0] = '0';
                string[1] = '\0';
                return string;
            }
            while (n != 0) {
                string[i++] = n % 10 + '0';
                n /= 10;
            }
            if (is_negative) {
                string[i++] = '-';
            }
            string[i] = '\0';
            for (int t = 0; t < i / 2; t++) { // Reverse string
                string[t] ^= string[i - t - 1];
                string[i - t - 1] ^= string[t];
                string[t] ^= string[i - t - 1];
            }
            return string;
        }
        /**
         * Get string length
         *
         * @param const char *
         * @return size_t length of string
         * */
        size_t get_string_length(const char *string) {
            size_t counter = 0;
            while (string[counter]) {
                counter++;
            }
            return counter;
        }

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
         * Returns a pointer to the buffer.
         *
         * @return char* to buffer
         * */
        char *get_buffer() {
            return buffer;
        }

        /**
         * Appends a string (source) at the end of the buffer (array)
         *
         * @param const char* source
         * @return char* to buffer
         * */
        char *append(const char *source) {
            int i = 0;
            size_t start = get_string_length(buffer);
            while (source[i]) {
                buffer[start++] = source[i++];
            }
            buffer[start] = '\0';
            return buffer;
        }

        /**
         * Appends a string (source) at the front of buffer (array)
         *
         * @param const char* source
         * @preturn char* to buffer
         * */
        char *append_front(const char *source) {
            const size_t length = get_string_length(source);
            unsigned int i = 0;
            for (; source[i]; i++) { // Make space for source
                buffer[i + length] = buffer[i];
            }
            buffer[i + length] = '\0';
            for (i = 0; i < length; i++) { // Put source in front of buffer
                buffer[i] = source[i];
            }
            return buffer;
        }

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
                                          const uint16_t &speed = 500) = 0;
    };
} // namespace r2d2::robot_arm