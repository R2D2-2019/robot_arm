#pragma once
#include <hwlib.hpp> // size_t, (u)intx_t
#include <vector3.hpp>

namespace r2d2::robot_arm {
    /**
     * Template Interface class for generating gcodes.
     * Has a few helper functions such as converting an int to a char.
     * Size represents the size of the char buffer array.
     * Note that a string of 4 characters, has a size of 5 with the '\0'
     * character
     * @param Size buffer size
     *
     */
    template <size_t Size>
    class gcode_generator_c {
    private:
        /**
         * Represents the size of the string currently in buffer
         */
        size_t str_len = 0;

        /** Checks whether the string to be added fits into the buffer
         * @true if it fits
         * @return false otherwise
         */
        bool string_fits(const char *string) {
            return get_string_length(string) + 1 + str_len <= Size;
        }

        /**
         * Reverses a string
         *
         * @param char*
         * @param int length
         */
        void reverse(char *string, int length) {
            int start = 0;
            length--;
            while (start < length) {
                std::swap(*(string + start), *(string + length));
                start++;
                length--;
            }
        }

    protected:
        /**
         * Buffer with Size as size.
         */
        char buffer[Size] = {'\0'};

        /**
         * Converts an int to a string.
         * Please note that the destination size must be 11 if you
         * want to store a max integer value (2.147.483.647) + '\0' = 11
         *
         * @param int number
         * @param char array
         */
        void int_to_string(int number, char *string) {
            int i = 0;
            bool is_negative = number < 0;
            int n = is_negative ? -number : number;
            if (n == 0) {
                string[0] = '0';
                string[1] = '\0';
                return;
            }
            while (n != 0) {
                string[i++] = n % 10 + '0';
                n /= 10;
            }
            if (is_negative) {
                string[i++] = '-';
            }
            string[i] = '\0';
            reverse(string, i);
        }

        /**
         * Get string length
         *
         * @param const char *
         * @return size_t length of string
         */
        size_t get_string_length(const char *string) {
            size_t counter = 0;
            while (string[counter]) {
                counter++;
            }
            return counter;
        }

    public:
        /** Returns the length of the string
         *
         * @return size_t
         */
        size_t length() {
            return str_len;
        }
        /**
         * Returns a pointer to the buffer.
         *
         * @return char* to buffer
         */
        char *get_buffer() {
            return buffer;
        }

        /**
         * Appends a string (source) at the end of the buffer (array)
         * Returns if source does not fit into buffer
         *
         * @param const char* sourcer
         */
        void append(const char *source) {
            if (!string_fits(source)) {
                return;
            }
            int i = 0;
            size_t start = get_string_length(buffer);
            while (source[i]) {
                buffer[start++] = source[i++];
            }
            buffer[start] = '\0';
            str_len += get_string_length(source);
        }

        /**
         * Appends a string (source) at the front of buffer (array)
         * Returns if source does not fit into buffer
         *
         * @param const char* source
         */
        void append_front(const char *source) {
            if (!string_fits(source)) {
                return;
            }
            const size_t string_len = get_string_length(source);
            str_len += string_len;
            unsigned int i = 0;
            for (; source[i]; i++) { // Make space for source
                buffer[i + string_len] = buffer[i];
            }
            buffer[i + string_len] = '\0';
            for (i = 0; i < string_len; i++) { // Put source in front of buffer
                buffer[i] = source[i];
            }
        }

        /**
         * Pure virtual function for gcode command.
         * Every robot arm might have different gcode commands.
         *
         *
         * @param coordinate_3D_c
         * @param uint8_t speed = 500
         */
        virtual void coordinate_to_gcode(const vector3i_c &coordinate,
                                         const uint16_t &speed = 500) = 0;
    };
} // namespace r2d2::robot_arm