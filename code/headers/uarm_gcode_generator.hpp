#include <gcode_generator.hpp>

namespace r2d2::robot_arm {
    template <size_t Size>
    class uarm_gcode_generator_c : public gcode_generator_c<Size> {
    public:

        /**
         * Converts a vector3i_c to a gcode command for uArm
         *
         * @param vector3i
         * @param uint8_t speed
         * */
        void coordinate_to_gcode(const vector3i_c &coordinate, const uint16_t &speed) {
            char x_string[11]; // max number of int digits (10) + '\0' = 11
            char y_string[11];
            char z_string[11];
            char speed_string[11];
            this->int_to_string(coordinate.x, x_string);
            this->int_to_string(coordinate.y, y_string);
            this->int_to_string(coordinate.z, z_string);
            this->int_to_string(speed, speed_string);
            this->append("#1 G0 X");
            this->append(x_string);
            this->append(" Y");
            this->append(y_string);
            this->append(" Z");
            this->append(z_string);
            this->append(" F");
            this->append(speed_string);
            this->append("\n");
        }

        void polar_coordinate_to_gcode(const vector3i_c &coordinate, const uint16_t &speed){
            char s_string[11]; // max number of int digits (10) + '\0' = 11
            char r_string[11];
            char h_string[11];
            char speed_string[11];
            this->int_to_string(coordinate.x, s_string);
            this->int_to_string(coordinate.y, r_string);
            this->int_to_string(coordinate.z, h_string);
            this->int_to_string(speed, speed_string);
            this->append("#2 G2201 S");
            this->append(s_string);
            this->append(" R");
            this->append(r_string);
            this->append(" H");
            this->append(h_string);
            this->append(" F");
            this->append(speed_string);
            this->append("\n");
        }

        void rotate_id_motor_degree_to_gcode(const uint8_t &id, const uint16_t &degree){
            char id_string[2];
            char degree_string[4];
            this->int_to_string(id, id_string);
            this->int_to_string(degree, degree_string);
            this->append("#3 G2202 N");
            this->append(id_string);
            this->append(" V");
            this->append(degree_string);
            this->append("\n");
        }

        void relative_displacement_to_gcode(const vector3i_c &coordinate, const uint16_t &speed) {
            char x_string[11]; // max number of int digits (10) + '\0' = 11
            char y_string[11];
            char z_string[11];
            char speed_string[11];
            this->int_to_string(coordinate.x, x_string);
            this->int_to_string(coordinate.y, y_string);
            this->int_to_string(coordinate.z, z_string);
            this->int_to_string(speed, speed_string);
            this->append("#4 G2204 X");
            this->append(x_string);
            this->append(" Y");
            this->append(y_string);
            this->append(" Z");
            this->append(z_string);
            this->append(" F");
            this->append(speed_string);
            this->append("\n");
        }

        void relative_displacement_polar_to_gcode(const vector3i_c &coordinate, const uint16_t &speed){
            char s_string[11]; // max number of int digits (10) + '\0' = 11
            char r_string[11];
            char h_string[11];
            char speed_string[11];
            this->int_to_string(coordinate.x, s_string);
            this->int_to_string(coordinate.y, r_string);
            this->int_to_string(coordinate.z, h_string);
            this->int_to_string(speed, speed_string);
            this->append("#5 G2205 S");
            this->append(s_string);
            this->append(" R");
            this->append(r_string);
            this->append(" H");
            this->append(h_string);
            this->append(" F");
            this->append(speed_string);
            this->append("\n");
        }

        void attach_all_joint_motors_to_gcode(){
            this->append("#6 M17\n");
        }

        void detach_all_joint_motors_to_gcode(){
            this->append("#7 M2019\n");
        }

        void return_cartesian_coordinates_by_speed_to_gcode(const uint16_t &speed){
            char speed_string[11];
            this->int_to_string(speed, speed_string);
            this->append("#8 M2120 V");
            this->append(speed_string);
            this->append("\n");
        }

        void attach_motor_by_id_to_gcode(const uint8_t &id){
            char id_string[2];
            this->int_to_string(id, id_string);
            this->append("#9 M2201 N");
            this->append(id_string);
            this->append("\n");
        }

        void detach_motor_by_id_to_gcode(const uint8_t &id){
            char id_string[2];
            this->int_to_string(id, id_string);
            this->append("#10 M2202 N");
            this->append(id_string);
            this->append("\n");
        }

        void check_attached_motor_by_id_to_gcode(const uint8_t &id){
            char id_string[2];
            this->int_to_string(id, id_string);
            this->append("#11 M2203 N");
            this->append(id_string);
            this->append("\n");
        }

        void set_buzzer_to_gcode(const uint16_t &frequency, const uint16_t &time){
            char frequency_string[11];
            char time_string[11];
            this->int_to_string(frequency, frequency_string);
            this->int_to_string(time, time_string);
            this->append("#12 M2210 F");
            this->append(frequency_string);
            this->append(" T");
            this->append(time_string);
            this->append("\n");
        }

        void convert_coordinates_to_angle_of_joints_to_gcode(const vector3i_c &coordinate){
            char x_string[11]; // max number of int digits (10) + '\0' = 11
            char y_string[11];
            char z_string[11];
            this->int_to_string(coordinate.x, x_string);
            this->int_to_string(coordinate.y, y_string);
            this->int_to_string(coordinate.z, z_string);
            this->append("#13 M2220 X");
            this->append(x_string);
            this->append(" Y");
            this->append(y_string);
            this->append(" Z");
            this->append(z_string);
            this->append("\n");
        }

        void convert_angle_of_joints_to_coordinates_to_gcode(const vector3i_c &angle){
            char b_string[11]; // max number of int digits (10) + '\0' = 11
            char l_string[11];
            char r_string[11];
            this->int_to_string(angle.x, b_string);
            this->int_to_string(angle.y, l_string);
            this->int_to_string(angle.z, r_string);
            this->append("#14 M2221 B");
            this->append(b_string);
            this->append(" L");
            this->append(l_string);
            this->append(" R");
            this->append(r_string);
            this->append("\n");
        }

        void check_posibility_of_coordinates_cartesian_polar_to_gecode(const vector3i_c &coordinate, const uint8_t &id){
            char x_string[11]; // max number of int digits (10) + '\0' = 11
            char y_string[11];
            char z_string[11];
            char id_string[2];
            this->int_to_string(coordinate.x, x_string);
            this->int_to_string(coordinate.y, y_string);
            this->int_to_string(coordinate.z, z_string);
            this->int_to_string(id, id_string);
            this->append("#15 M2222 X");
            this->append(x_string);
            this->append(" Y");
            this->append(y_string);
            this->append(" Z");
            this->append(z_string);
            this->append(" P");
            this->append(id_string);
            this->append("\n");
        }

        void set_current_position_head_to_reference_position_to_gcode(){
            this->append("#16 M2401\n");
        }

        void init_to_gcode(const uint8_t &on_off){
            char on_off_string[2];
            this->int_to_string(on_off, on_off_string);
            this->append("#1 M2122 V");
            this->append(on_off_string);
            this->append("\n");
        }

        void get_current_angle_of_joints_to_gecode(){
            this->append("#17 P2200\n");
        }

        void get_device_name_to_gecode(){
            this->append("#18 P2201\n");
        }

        void get_hardware_version_to_gecode(){
            this->append("#19 P2202\n");
        }

        void get_software_version_to_gcode(){
            this->append("#20 P2203\n");
        }
        
        void get_API_version_to_gcode(){
            this->append("#21 P2204\n");
        }

        void get_UID_to_gcode(){
            this->append("#22 P2205\n");
        }

        void get_angle_of_joint_id(const uint8_t &id){
            char id_string[2];
            this->int_to_string(id, id_string);
            this->append("#23 P2206 N");
            this->append(id);
            this->append("\n");
        }

        void get_current_coordinates(){
            this->append("#24 P2220\n");
        }

        void get_current_polar_coordinates(){
            this->append("#25 P2221\n");
        }

        void get_status_power_connection(){
            this->append("#26 P2234\n");
        }

        void check_current_status(){
            this->append("#27 P2400\n");
        }

    };
} // namespace r2d2::robot_arm