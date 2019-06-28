#include <uarm_swift_pro.hpp>

namespace r2d2::robot_arm {
    uarm_swift_pro_c::uarm_swift_pro_c(usart_c &usart_bus,base_comm_c &comm): 
            robot_arm_interface_c(comm),
            usart_bus(usart_bus) {
    }

   //------------------MOVING COMMANDS------------------//
    void uarm_swift_pro_c::move_head_to_coordinate(const vector3i_c &coordinate, 
                                                            const uint16_t &speed) {
        gcode_generator.coordinate_to_gcode(coordinate, speed);
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    void uarm_swift_pro_c::move_head_to_coordinate(const vector3i_c &coordinate) {
        gcode_generator.coordinate_to_gcode(coordinate, default_speed);
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    void uarm_swift_pro_c::move_head_to_polar_coordinate(const vector3i_c &coordinate, 
                                                            const uint16_t &speed){
        gcode_generator.polar_coordinate_to_gcode(coordinate, speed);
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    void uarm_swift_pro_c::rotate_id_motor_to_degree(const uint8_t &id, const uint16_t &degree){
        gcode_generator.rotate_id_motor_degree_to_gcode(id, degree);
        this->send_command(gcode_generator.get_buffer()); 
        this->debug();
    }

    void uarm_swift_pro_c::relative_displacement_head(const vector3i_c &coordinate, const uint16_t &speed){
        gcode_generator.relative_displacement_to_gcode(coordinate, speed);
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    void uarm_swift_pro_c::relative_displacement_polar_head(const vector3i_c &coordinate, const uint16_t &speed){
        gcode_generator.relative_displacement_polar_to_gcode(coordinate, speed);
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }



    //------------------SETTING COMMANDS------------------//

    void uarm_swift_pro_c::init(const uint8_t &on_off) {
        gcode_generator.init(on_off);
        this->send_command(gcode_generator.get_buffer()); // report when stop
        this->debug();
    }

    void uarm_swift_pro_c::attach_all_joint_motors() {
        gcode_generator.attach_all_joint_motors_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    void uarm_swift_pro_c::detach_all_joint_motors() {
        gcode_generator.detach_all_joint_motors_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    void uarm_swift_pro_c::return_cartesian_coordinates_by_speed(const uint16_t &speed){
        gcode_generator.return_cartesian_coordinates_by_speed_to_gcode(speed);
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    void uarm_swift_pro_c::attach_motor_by_id(const uint8_t &id){
        gcode_generator.attach_motor_by_id_to_gcode(id);
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    void uarm_swift_pro_c::detach_motor_by_id(const uint8_t &id){
        gcode_generator.detach_motor_by_id_to_gcode(id);
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    void uarm_swift_pro_c::check_attached_motor_by_id(const uint8_t &id){
        gcode_generator.check_attached_motor_by_id_to_gcode(id);
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    void uarm_swift_pro_c::set_buzzer(const uint16_t &frequence, const uint16_t &time){
        gcode_generator.set_buzzer_to_gcode(frequence,time);
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    //------------------ESSENTIAL METHODS------------------//

    void uarm_swift_pro_c::debug(){
        char debug = '0';
        while ( debug != '\n'){
            debug = this->usart_bus.getc();
            hwlib::cout << debug;
        }
    }

    bool uarm_swift_pro_c::send_command(const char *command) {
        this->usart_bus << command;
        return true;
    }

} // namespace r2d2::robot_arm
