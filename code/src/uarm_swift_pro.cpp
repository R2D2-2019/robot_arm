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
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::move_head_to_coordinate(const vector3i_c &coordinate) {
        gcode_generator.coordinate_to_gcode(coordinate, default_speed);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::move_head_to_polar_coordinate(const vector3i_c &coordinate, 
                                                            const uint16_t &speed){
        gcode_generator.polar_coordinate_to_gcode(coordinate, speed);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();

    }

    void uarm_swift_pro_c::rotate_id_motor_to_degree(const uint8_t &id, const uint16_t &degree){
        gcode_generator.rotate_id_motor_degree_to_gcode(id, degree);
        this->send_command(gcode_generator.get_buffer()); 
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::relative_displacement_head(const vector3i_c &coordinate, const uint16_t &speed){
        gcode_generator.relative_displacement_to_gcode(coordinate, speed);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::relative_displacement_polar_head(const vector3i_c &coordinate, const uint16_t &speed){
        gcode_generator.relative_displacement_polar_to_gcode(coordinate, speed);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }



    //------------------SETTING COMMANDS------------------//

    void uarm_swift_pro_c::init(const uint8_t &on_off) {
        gcode_generator.init_to_gcode(on_off);
        this->send_command(gcode_generator.get_buffer()); // report when stop
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::attach_all_joint_motors() {
        gcode_generator.attach_all_joint_motors_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::detach_all_joint_motors() {
        gcode_generator.detach_all_joint_motors_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::return_cartesian_coordinates_by_speed(const uint16_t &speed){
        gcode_generator.return_cartesian_coordinates_by_speed_to_gcode(speed);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::attach_motor_by_id(const uint8_t &id){
        gcode_generator.attach_motor_by_id_to_gcode(id);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::detach_motor_by_id(const uint8_t &id){
        gcode_generator.detach_motor_by_id_to_gcode(id);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::check_attached_motor_by_id(const uint8_t &id){
        gcode_generator.check_attached_motor_by_id_to_gcode(id);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::set_buzzer(const uint16_t &frequence, const uint16_t &time){
        gcode_generator.set_buzzer_to_gcode(frequence,time);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::convert_coordinates_to_angle_of_joints(const vector3i_c &coordinate){
        gcode_generator.convert_coordinates_to_angle_of_joints_to_gcode(coordinate);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::convert_angle_of_joints_to_coordinates(const vector3i_c &angle){
        gcode_generator.convert_angle_of_joints_to_coordinates_to_gcode(angle);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::check_posibility_of_coordinates_cartesian_polar(const vector3i_c &coordinate, const uint8_t &id){
        gcode_generator.check_posibility_of_coordinates_cartesian_polar_to_gecode(coordinate, id);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::set_current_position_head_to_reference_position(){
        gcode_generator.set_current_position_head_to_reference_position_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::switch_uart2_uart0(){
        gcode_generator.switch_uart2_uart0();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();

    }

    void uarm_swift_pro_c::gripper_close_open(){
        gcode_generator.gripper_close_open();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    //-------------------QUERYING METHODS------------------//

    void uarm_swift_pro_c::get_current_angle_of_joints(){
        gcode_generator.get_current_angle_of_joints_to_gecode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::get_device_name(){
        gcode_generator.get_device_name_to_gecode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::get_hardware_version(){
        gcode_generator.get_hardware_version_to_gecode();
        this->send_command(gcode_generator.get_buffer());
        this->debug();
    }

    void uarm_swift_pro_c::get_software_version(){
        gcode_generator.get_software_version_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::get_API_version(){
        gcode_generator.get_API_version_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::get_UID(){
        gcode_generator.get_UID_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::get_angle_of_joint_id(const uint8_t &id){
        gcode_generator.get_angle_of_joint_id_to_gcode(id);
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::get_current_coordinates(){
        gcode_generator.get_current_coordinate_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::get_current_polar_coordinates(){
        gcode_generator.get_current_polar_coordinates_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::get_status_power_connection(){
        gcode_generator.get_status_power_connection_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
        this->debug();
    }

    void uarm_swift_pro_c::check_current_status(){
        gcode_generator.check_current_status_to_gcode();
        this->send_command(gcode_generator.get_buffer());
        gcode_generator.reset_buffer();
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
        hwlib::cout << "send_command: " <<command << hwlib::endl;
        return true;
    }

} // namespace r2d2::robot_arm
