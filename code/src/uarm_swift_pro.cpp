#include <uarm_swift_pro.hpp>

namespace r2d2::robot_arm {
    uarm_swift_pro_c::uarm_swift_pro_c(usart_c &usart_bus)
        : usart_bus(usart_bus) {
    }
    
    void uarm_swift_pro_c::move_head_to_coordinate(const vector3i_c &coordinate, const uint16_t &speed) {
        gcode_generator.coordinate_to_gcode(coordinate, speed);
        this->send_command(gcode_generator.get_buffer());
    }

    void uarm_swift_pro_c::move_head_to_coordinate(const vector3i_c &coordinate) {
        gcode_generator.coordinate_to_gcode(coordinate, default_speed);
        this->send_command(gcode_generator.get_buffer());
    }

    void uarm_swift_pro_c::move_head_to_polar_coordinate(const vector3i_c &coordinate, const uint16_t &speed){
        gcode_generator.coordinate_to_gcode(coordinate, speed);
        this->send_command(gcode_generator.get_buffer());
    }

    void uarm_swift_pro_c::rotate_head(const int16_t &rotation) {
        // TODO impl rotate head uarm swift pro
    }

    void uarm_swift_pro_c::init() {
        this->send_command("#n M2122 V1\n"); // report when stop
    }

    bool uarm_swift_pro_c::check_connection() {
        // TODO impl check_connection()
        return true;
    }

    bool uarm_swift_pro_c::send_command(const char *command) {
        this->usart_bus << command;
        return true;
    }

    void uarm_swift_pro_c::move_joint(const int &joint_id, const int &angle) {
        // TODO impl uarm_swift_c::move_joint
    }

} // namespace r2d2::robot_arm
