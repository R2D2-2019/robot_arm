#pragma once

#include <hardware_usart.hpp>
#include <hwlib.hpp>
#include <robot_arm.hpp>

namespace r2d2::robot_arm {
    class uarm_swift_c : public robot_arm_c {
    private:
    public:
        uarm_swift_c(r2d2::hardware_usart_c usart_bus);
        // uarm_swift_c(unsigned int bautrate);
        bool send_command(const char *command) override {
            return true;
        };
        bool move_joint(int joint_id, int angle) override;
        // char *uarm_swift_c::int_to_char(int number, char *dest);
    };

} // namespace r2d2::robot_arm