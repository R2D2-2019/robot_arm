#pragma once
#include <gcode_generator.hpp>

namespace r2d2::robot_arm {
    template <size_t Size>
    class uarm_gcode_generator_c : public gcode_generator_c<Size> {
    public:

        /**
         * @brief coordinate to gcode
         * Makes a vector3i_c cartesian coordinate gcode command for uArm where the head 
         * will go 
         *
         * @param coordinate cartesian integer coordinate for the head (XYZ)
         * @param speed movement speed in mm/min 
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

        /**
         * @brief polar coordinate to gcode
         * Makes a vector3i_c polar coordinate gcode command for uArm where the head 
         * will go.
         * 
         * @param coordinate polar coordinates, S is stretch(mm), R is rotation(degree),H is height(mm)
         * @param speed movement speed in mm/min
         */
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

        /**
         * @brief rotate id motor degree to gcode
         * Makes for a specific motor(by id) the degree the motor has to go gcode command for the uarm
         * 
         * @param id id of joints (0 ~ 3)
         * @param degree degree of angle (0 ~ 180)
         */
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

        /**
         * @brief relative displacement to gcode
         * Makes the relative displavement of the head gcode command for the uarm
         * 
         * @param coordinate cartesian integer coordinate for the head (XYZ)
         * @param speed movement speed in mm/min
         */
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

        /**
         * @brief relative displacement polar to gcode
         * Makes the relative polar displacement of the head gcode command for the uarm
         * 
         * @param coordinate polar coordinates, S is stretch(mm), R is rotation(degree),H is height(mm)
         * @param speed movement speed in mm/min
         */
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

    	/**
         * @brief attach all joint motors to gcode
         * Makes the attach all joint motors gcode command for the uarm
         */
        void attach_all_joint_motors_to_gcode(){
            this->append("#6 M17\n");
        }

        /**
         * @brief detach all joint motors to gcode
         * Makes the detach all joint motors gcode command for the uarm
         */
        void detach_all_joint_motors_to_gcode(){
            this->append("#7 M2019\n");
        }
        /**
         * @brief return cartesian coordinates by speed to gcode
         * Makes the cartesian coordinates by speed gcode command for the uarm
         * 
         * @param speed is time(seconds) 
         */
        void return_cartesian_coordinates_by_speed_to_gcode(const uint16_t &speed){
            char speed_string[11];
            this->int_to_string(speed, speed_string);
            this->append("#8 M2120 V");
            this->append(speed_string);
            this->append("\n");
        }

        /**
         * @brief attach motor by id to gcode
         * Makes the attach motor by id gcode command for the uarm
         * 
         * @param id id of joints (0 ~ 3)
         */
        void attach_motor_by_id_to_gcode(const uint8_t &id){
            char id_string[2];
            this->int_to_string(id, id_string);
            this->append("#9 M2201 N");
            this->append(id_string);
            this->append("\n");
        }

        /**
         * @brief detach motor by id to gcode
         * Makes the detach motor by id gcode command for the uarm
         * 
         * @param id id of joints (0 ~ 3)
         */
        void detach_motor_by_id_to_gcode(const uint8_t &id){
            char id_string[2];
            this->int_to_string(id, id_string);
            this->append("#10 M2202 N");
            this->append(id_string);
            this->append("\n");
        }

        /**
         * @brief check attached motor by id to gcode
         * Makes the check motor by id gcode command for the uarm
         * 
         * @param id id of joints (0 ~ 3)
         */
        void check_attached_motor_by_id_to_gcode(const uint8_t &id){
            char id_string[2];
            this->int_to_string(id, id_string);
            this->append("#11 M2203 N");
            this->append(id_string);
            this->append("\n");
        }

        /**
         * @brief set buzzer to gcode
         * Makes the set buzzer gcode command for the uarm
         * 
         * @param frequence frequence of buzzer (hertz)
         * @param time the amount of time the buzzer turns on (ms)
         */
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

        /**
         * @brief convert coordinates to angle of joints to gcode
         * Makes the convert coordinates to angle of joints gcode command for the uarm
         * 
         * @param coordinate cartesian integer coordinate(XYZ)
         */
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

        /**
         * @brief convert angle of joints to coordinates to gcode
         * Makes the convert angle of joints to coordinates gcode command for the uarm
         * 
         * @param angle angle of the joints: vector3("B joint 0","L joint 1","R joints 2") from 0~180 degree
         */
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

        /**
         * @brief check posibility of coordinates cartesian polar to gcode
         * Makes the check posibility of coordinates cartesian polar gcode command for the uarm
         * 
         * @param coordinate cartesian integer coordinate(XYZ) 
         * @param id 0 = cartesian , 1 = polar
         */
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

    	/**
         * @brief set current position head to reference position to gcode
         * Makes the set current position head to reference position gcode command for the uarm
         */
        void set_current_position_head_to_reference_position_to_gcode(){
            this->append("#16 M2401\n");
        }

        /**
         * @brief Initialization to gcode
         * Makes the initialization gcode command for the uarm
         * 
         * @parram on_off to set the uarm on or off
         */
        void init_to_gcode(const uint8_t &on_off){
            char on_off_string[2];
            this->int_to_string(on_off, on_off_string);
            this->append("#17 M2122 V");
            this->append(on_off_string);
            this->append("\n");
        }

        /**
         * @brief get current angle of joints to gcode
         * Makes the get current angle of the joints gcode command for the uarm
         */
        void get_current_angle_of_joints_to_gecode(){
            this->append("#18 P2200\n");
        }

        /**
         * @brief get device name to gcode
         * Makes the get device name gcode command for the uarm
         */
        void get_device_name_to_gecode(){
            this->append("#19 P2201\n");
        }

        /**
         * @brief get hardware version to gcode
         * Makes the get device name gcode command for the uarm
         */
        void get_hardware_version_to_gecode(){
            this->append("#20 P2202\n");
        }

        /**
         * @brief get software version to gcode
         * Makes the get software version gcode command for the uarm
         */
        void get_software_version_to_gcode(){
            this->append("#21 P2203\n");
        }
        
        /**
         * @brief get API version to gcode
         * Makes the get API version gcode command for the uarm
         */
        void get_API_version_to_gcode(){
            this->append("#22 P2204\n");
        }

        /**
         * @brief get UID to gcode
         * Makes the get UID gcode command for the uarm for the uarm
         */
        void get_UID_to_gcode(){
            this->append("#23 P2205\n");
        }

        /**
         * @brief get angle of joint id to gcode
         * Makes the get angle of joint id gcode command for the uarm
         * 
         * @param id id of joints (0 ~ 2)
         */
        void get_angle_of_joint_id_to_gcode(const uint8_t &id){
            char id_string[2];
            this->int_to_string(id, id_string);
            this->append("#24 P2206 N");
            this->append(id_string);
            this->append("\n");
        }

        /**
         * @brief get current coordinates to gcode
         * Makes the get current coordinates gcode command for the uarm
         */
        void get_current_coordinate_to_gcode(){
            this->append("#25 P2220\n");
        }

        /**
         * @brief get current polar coordinates to gcode
         * Makes the get current polar coordinates gcode command for the uarm
         */
        void get_current_polar_coordinates_to_gcode(){
            this->append("#26 P2221\n");
        }

        /**
         * @brief get status power connection to gcode
         * Makes the get tatus power connections gcode command for the uarm
         */
        void get_status_power_connection_to_gcode(){
            this->append("#27 P2234\n");
        }

        /**
         * @brief check current status to gcode
         * Makes the check current status gcode command for the uarm
         */
        void check_current_status_to_gcode(){
            this->append("#28 P2400\n");
        }

    };
} // namespace r2d2::robot_arm