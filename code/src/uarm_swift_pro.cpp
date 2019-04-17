#include <uarm_swift_pro.hpp>

r2d2::robot_arm::uarm_swift_pro_c::uarm_swift_pro_c(const r2d2::hardware_usart_c &usart_bus)
        : usart_bus(usart_bus) {
}
r2d2::robot_arm::uarm_swift_pro_c::uarm_swift_pro_c(unsigned int &bautrate,
                         r2d2::uart_ports_c &usart_port)
        : usart_bus(bautrate, usart_port) {
}


void r2d2::robot_arm::uarm_swift_pro_c::move_head_to_coordinate(const vector3i_c &coordinate,
                                                                const uint16_t speed) {

    auto command = r2d2::robot_arm::uarm_swift_pro_c::gcode_generator.coordinate_to_gcode(coordinate, speed);

    this->send_command(command);
}

void r2d2::robot_arm::uarm_swift_pro_c::move_head_to_coordinate(const vector3i_c &coordinate) {
    hwlib::cout << coordinate.x << coordinate.y << coordinate.z  << "\n";

    auto command = r2d2::robot_arm::uarm_swift_pro_c::gcode_generator.coordinate_to_gcode(coordinate, r2d2::robot_arm::uarm_swift_pro_c::default_speed);
    hwlib::cout << command << "\n";
    this->send_command(command);
}


void r2d2::robot_arm::uarm_swift_pro_c::rotate_head(const int16_t &rotation) {
    // TODO impl rotate head uarm swift pro
}



void r2d2::robot_arm::uarm_swift_pro_c::init() {
    this->send_command("#n M2122 V1\n"); // report when stop
}

bool r2d2::robot_arm::uarm_swift_pro_c::check_connection() {
    // TODO impl check_connection()
    return true;
}

bool r2d2::robot_arm::uarm_swift_pro_c::send_command(const char *command) {
    this->usart_bus << command;
    return true;
}

void r2d2::robot_arm::uarm_swift_pro_c::move_joint(const int &joint_id, const int &angle) {
    // TODO impl uarm_swift_c::move_joint
}

