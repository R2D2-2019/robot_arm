#include "gcode_generator_c.hpp"
#include <iostream>
namespace r2d2::robot_arm {
    char *gcode_generator_c::int_to_string(int axis, char *destination) const {
        int i = 0;
        bool is_negative = axis < 0;
        unsigned int n = is_negative ? -axis : axis;
        if (n == 0) {
            destination[0] = '0';
            destination[1] = '\0';
            return destination;
        }
        while (n != 0) {
            destination[i++] = n % 10 + '0';
            n /= 10;
        }
        if (is_negative) {
            destination[i++] = '-';
        }
        destination[i] = '\0';
        for (int t = 0; t < i / 2; t++)	{ // Reverse string
		    destination[t] ^= destination[i - t - 1];
		    destination[i - t - 1] ^= destination[t];
		    destination[t] ^= destination[i - t - 1];
	    }
        return destination;
    }

    char *gcode_generator_c::append(char *destination, const char *source) const {
        int i = 0;
        size_t start = std::strlen(destination) + 1;
        while (source[i]) {
            destination[start++] = source[i++];
        }
        return destination;
    }

    char *gcode_generator_c::append_front(char *destination, const char *source) const {
        const size_t length = std::strlen(source);
        unsigned int i = 0;
        for (; destination[i]; i++) {
            destination[i] = destination[i + length];
        }
        i = 0;
        for (; source[i]; i++) {
            destination[i] = source[i];
        }
        return destination;
    }
} // namespace r2d2::robot_arm