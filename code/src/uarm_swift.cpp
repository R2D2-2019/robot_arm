#include "uarm_swift.hpp"
#include <cstring>

namespace r2d2::robot_arm {
    uarm_swift_c::uarm_swift_c(r2d2::hardware_usart_c usart_bus)
        : robot_arm_c(usart_bus) {
    }

    bool uarm_swift_c::move_joint(int joint_id, int angle) {
        char command[40] = "#n G2202 N0 V10\n";

        /*char ch_joint[] = " N"; // + (char)joint_id;
        char ch_angle[] = " V"; //+ (char)angle;
        char *j = intToChar(joint_id, j);
        char *a = intToChar(angle, a);

        strncat(ch_joint, j, sizeof(ch_joint) - strlen(j) - 1);
        strncat(ch_angle, a, sizeof(ch_angle) - strlen(a) - 1);

        strncat(command, ch_joint, sizeof(command) - strlen(ch_joint) - 1);
        strncat(command, ch_angle, sizeof(command) - strlen(ch_angle) -
        1);*/
        for (char j : command) {

            this->usart_bus.putc(j);
            hwlib::cout << j;
        };
        // hwlib::cout << command;

        return true;
    };

    /*char *uarm_swift_c::int_to_char(int number, char *dest) {
        if ((number / 10) == 0) {
            *dest++ = number + '0';
            *dest = '\0';
            return dest;
        }

        dest = int_to_char(number / 10, dest);
        *dest++ = (number % 10) + '0';
        *dest = '\0';
        return dest;
    };*/

} // namespace r2d2::robot_arm