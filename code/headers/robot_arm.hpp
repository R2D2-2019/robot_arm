#pragma once

#include <hardware_usart.hpp>
#include <hwlib.hpp>

namespace r2d2::robot_arm {
    class robot_arm_c {
    protected:
        // unsigned int bautrate;

        // r2d2::uart_ports_c usart_port;
        r2d2::hardware_usart_c usart_bus;

    public:
        // robot_arm_c(unsigned int bautrate, r2d2::hardware_usart_c usart_bus);
        robot_arm_c(r2d2::hardware_usart_c usart_bus);
        virtual bool send_command(const char *command) {
            return false;
        };
        virtual bool move_joint(int joint_id, int angle) {
            return false;
        };
    }; // namespace r2d2::robot_arm

} // namespace r2d2::robot_arm