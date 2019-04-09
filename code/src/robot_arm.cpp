#include "robot_arm.hpp"

namespace r2d2::robot_arm {
    robot_arm_c::robot_arm_c(r2d2::hardware_usart_c usart_bus)
        : usart_bus(usart_bus) {
    }
    robot_arm_c::robot_arm_c(unsigned int bautrate,
                             r2d2::uart_ports_c usart_port)
        : usart_bus(bautrate, usart_port) {
    }
} // namespace r2d2::robot_arm
