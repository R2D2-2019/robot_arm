#include "uarm_swift.hpp"
#include <cstring>

namespace r2d2::robot_arm {
    uarm_swift_c::uarm_swift_c(r2d2::hardware_usart_c usart_bus)
        : robot_arm_c(usart_bus) {
    }

    uarm_swift_c::uarm_swift_c(unsigned int bautrate,
                               r2d2::uart_ports_c usart_port)
        : robot_arm_c(bautrate, usart_port) {
    }

    bool uarm_swift_c::send_command(const char *command) {
        this->usart_bus << command;
        return true;
    }

    void uarm_swift_c::move_joint(int joint_id, int angle) {
    }

    void uarm_swift_c::move_head_towards(int x, int y, int z, int speed) {
        char command[] = "#n G0 X100 Y100 Z100 F1000\n";
        usart_bus << command;
    }

} // namespace r2d2::robot_arm