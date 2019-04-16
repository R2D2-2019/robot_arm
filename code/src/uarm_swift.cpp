#include <cstring>
#include <uarm_swift.hpp>

namespace r2d2::robot_arm {
    uarm_swift_c::uarm_swift_c(r2d2::hardware_usart_c &usart_bus)
        : robot_arm_c(usart_bus) {
        this->init();
    }

    uarm_swift_c::uarm_swift_c(unsigned int &bautrate,
                               r2d2::uart_ports_c &usart_port)
        : robot_arm_c(bautrate, usart_port) {
        this->init();
    }

    void uarm_swift_c::init() {
        this->send_command("#n M2122 V1\n"); // report when stop
    }

    bool check_connection() {
        return true;
    }

    bool uarm_swift_c::send_command(const char *command) {
        this->usart_bus << command;
        return true;
    }

    void uarm_swift_c::move_joint(int &joint_id, int &angle) {
    }

    void uarm_swift_c::move_head_to_coordinate(vector3i_c &coordinate,
                                               int speed) {
        auto command = gcode_generator.coordinate_to_gcode(coordinate, speed);

        this->send_command(command);
    }

} // namespace r2d2::robot_arm