#include "gcode_generator.hpp"
#include <iostream>
namespace r2d2::robot_arm {
    void gcode_generator::reverse(char *string, uint8_t length) const {
        int start = 0;
        length -= 1;
        while (start < length) {
            std::swap(*(string + start), *(string + length));
            start++;
            length--;
        }
    }

    char *gcode_generator::int_to_string(int axis, char *destination) const {
        uint8_t i = 0;
        uint8_t individual_digit;
        bool is_negative = axis < 0;

        if (axis == 0) {
            destination[i++] = '0';
            destination[i] = '\0';
            return destination;
        }
        if (is_negative) {
            axis = -axis;
        }
        while (axis != 0) {
            individual_digit = axis % 10;
            destination[i++] = axis > 9 ? (individual_digit - 10) + 'a'
                                        : individual_digit + '0';
            axis /= 10;
        }
        if (is_negative) {
            destination[i++] = '-';
        }
        destination[i] = '\0';
        return destination;
    }

    char *gcode_generator::append(char *destination, const char *source) {
        int i = 0;
        size_t start = std::strlen(destination) + 1;
        while (source[i]) {
            destination[start++] = source[i++];
        }
        return destination;
    }

    char *gcode_generator::append_front(char *destination, const char *source) {
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