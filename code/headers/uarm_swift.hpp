#pragma once

#include "robot_arm.hpp"
#include "uarm_gcode_generator_c.hpp"
#include "vector3_c.hpp"
#include <hardware_usart.hpp>
#include <hwlib.hpp>

namespace r2d2::robot_arm {
    class uarm_swift_c : public robot_arm_c {
    private:
        uarm_gcode_generator_c<50> gcode_generator;

    public:
        uarm_swift_c(r2d2::hardware_usart_c usart_bus);
        uarm_swift_c(unsigned int bautrate, r2d2::uart_ports_c usart_port);

        void init() override;
        bool check_connection() override;

        bool send_command(const char *command) override;
        void move_joint(int joint_id, int angle) override;
        void move_head_to_coordinate(vector3i_c coordinate, int speed) override;
    };

} // namespace r2d2::robot_arm