#include "gcode_generator_c.hpp"
#include <stdexcept>

namespace r2d2::robot_arm {
    gcode_generator_c::gcode_generator_c(char *buffer):
        buffer(buffer) {
            if (!strcmp(buffer, "") == 0) { // if buffer is not initialized with ""
                throw std::invalid_argument("Error: buffer is empty. Initialize buffer with \"\"");
            }
        }

    char *gcode_generator_c::get_buffer() {
        return buffer;
    }

    char *gcode_generator_c::int_to_string(int axis, char *string) const {
        int i = 0;
        bool is_negative = axis < 0;
        unsigned int n = is_negative ? -axis : axis;
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
        for (int t = 0; t < i / 2; t++)	{ // Reverse string
		    string[t] ^= string[i - t - 1];
		    string[i - t - 1] ^= string[t];
		    string[t] ^= string[i - t - 1];
	    }
        return string;
    }

    char *gcode_generator_c::append(const char *source) const {
        int i = 0;
        size_t start = std::strlen(buffer); 
        while (source[i]) {
            buffer[start++] = source[i++];
        }
        buffer[start] = '\0';
        return buffer;
    }

    char *gcode_generator_c::append_front(const char *source) const {
        const size_t length = std::strlen(source);
        unsigned int i = 0;
        for (; source[i]; i++) { // Make space for source
            buffer[i + length] = buffer[i];
        }
        for (i = 0; i < length; i++) { // Put source in front of buffer
            buffer[i] = source[i];
        }
        return buffer;
    }
} // namespace r2d2::robot_arm