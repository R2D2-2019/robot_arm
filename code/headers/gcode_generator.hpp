#pragma once
#include <vector3.hpp>
#include <cstddef> // size_t, (u)intx_t
#include <cstdint>
#include <algorithm>
#include <string.h>

namespace r2d2::robot_arm {
    /**
     * @brief
     * Template Interface class for generating gcodes.
     * Has a few helper functions such as converting an int to a char.
     * Size represents the size of the char buffer array.
     * Note that a string of 4 characters, has a size of 5 with the '\0'
     * character
     * 
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

        /** 
         * @brief
         * Checks whether the string to be added fits into the buffer
         * 
         * @param string A pointer of the string that needs to be checked 
         * @return A bool, True if the string fits False if it does not
         */
        bool string_fits(const char *string) const{
            return get_string_length(string) + 1 + str_len <= Size;
        }

        /**
         * @brief
         * Reverses a string
         *
         * @param string The string that needs to be reversed
         * @param length The length of the string
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
         * @brief
         * Converts an int to a string.
         * Please note that the destination size must be 11 if you
         * want to store a max integer value (2.147.483.647) + '\0' = 11
         *
         * @param number The number that needs to be converted to a string
         * @param string The char pointer that will contain the number
         */
        void int_to_string(int number, char *string) {
            int i = 0;
            bool is_negative = number < 0;
            int positive_number = is_negative ? -number : number;
            if (positive_number == 0) {
                string[0] = '0';
                string[1] = '\0';
                return;
            }
            while (positive_number != 0) {
                string[i++] = positive_number % 10 + '0';
                positive_number /= 10;
            }
            if (is_negative) {
                string[i++] = '-';
            }
            string[i] = '\0';
            reverse(string, i);
        }

        /**
         * @brief
         * Get string length
         *
         * @param string The string that we want the length of
         * @return Length of string as size_t
         */
        size_t get_string_length(const char *string) const{
            size_t counter = 0;
            while (string[counter]) {
                counter++;
            }
            return counter;
        }

    public:
        /** 
         * @brief
         * Returns the length of the string
         *
         * @return Saved length of string
         */
        size_t length() const{
            return str_len;
        }
        /**
         * @brief
         * Returns a pointer to the buffer.
         *
         * @return return buffer as char pointer
         */
        char *get_buffer() {
            return buffer;
        }

        void reset_buffer() {
            memset(buffer, 0, sizeof(buffer));
        }

        /**
         * @brief
         * Appends a string (source) at the end of the buffer (array)
         * Returns if source does not fit into buffer
         *
         * @param source The string that needs to be added to the end of the buffer
         */
        void append(const char *source) {
            int i = 0;
            size_t start = get_string_length(buffer);
            while (source[i]) {
                buffer[start++] = source[i++];
            }
            buffer[start] = '\0';
            str_len += get_string_length(source);
        }

        /**
         * @brief
         * Appends a string (source) at the front of buffer (array)
         * Returns if source does not fit into buffer
         *
         * @param source The string that needs to be added to the front of the buffer
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
         * @brief
         * Pure virtual function for gcode command.
         * Every robot arm might have different gcode commands.
         *
         * @param coordinate the coordinate that needs to be converted to gcode
         * @param speed the speed the arm needs to move at defaulted at 500
         */
        virtual void coordinate_to_gcode(const vector3i_c &coordinate,
                                         const uint16_t &speed = 500) = 0;
    };
} // namespace r2d2::robot_arm
