#pragma once

#include <hardware_usart.hpp>
#include <hwlib.hpp>
#include <robot_arm.hpp>

namespace r2d2::robot_arm {
    class uarm_swift_c : public robot_arm_c {
    private:
    public:
        uarm_swift_c(r2d2::hardware_usart_c usart_bus);
        uarm_swift_c(unsigned int bautrate, r2d2::uart_ports_c usart_port);
        bool send_command(const char *command) override;
        void move_joint(int joint_id, int angle) override;
        void move_head_towards(int x, int y, int z, int speed) override;
    };

} // namespace r2d2::robot_arm