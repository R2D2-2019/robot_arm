#include "robot_arm.hpp"

namespace r2d2::robot_arm {
    /*robot_arm_c::robot_arm_c(unsigned int bautrate,
                             r2d2::hardware_usart_c usart_bus)
        : bautrate(bautrate), usart_bus(usart_bus) {
    }*/
    robot_arm_c::robot_arm_c(r2d2::hardware_usart_c usart_bus)
        : usart_bus(usart_bus) {
    }
} // namespace r2d2::robot_arm
