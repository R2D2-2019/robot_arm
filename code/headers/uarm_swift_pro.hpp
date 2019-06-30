#pragma once

#include <cstring>
#include <hwlib.hpp>
#include <robot_arm_interface.hpp>
#include <uarm_gcode_generator.hpp>
#include <usart_connection.hpp>
#include <vector3.hpp>

/**
 * Class uArm_swift_pro provides a implementation for uArm swift pro.
 */
namespace r2d2::robot_arm {
    class uarm_swift_pro_c : public robot_arm_interface_c {
    private:
        using usart_c = r2d2::usart::usart_connection_c;
        uarm_gcode_generator_c<50> gcode_generator;
        usart_c &usart_bus;

    protected:
        const uint16_t default_speed = 1000;

    public:
        /**
         * @brief constructor
         * Robot arm constructor, needs an usart bus for communication and base_comm_c for 
         * can bus implementation
         * 
         * @param usart_bus usart bus for communication with the uarm
         * @param comm internal communication for can bus
         */
        uarm_swift_pro_c(usart_c &usart_bus, base_comm_c &comm);

        /**
         * @brief Check connection
         * Function to check whether the connection with the arm is right or not
         *
         * @return true means connection is right
         * @return false means connection is wrong
         */
        bool check_connection();

        /**
         * @brief Sending command to arm
         * Sends false as default
         *
         * @param command
         * @return false when something went wrong with sending
         * @return true when command correctly sent
         */
        bool send_command(const char *command);

        /**
         * @brief Move arm's head to cartesian coordinate
         * Moves head of robot arm head/end effector towards the 3D coordinate
         * [x,y,z] The speed is default at 500 mm/min
         *
         * @param coordinate cartesian integer coordinate for the head (XYZ)
         * @param speed movement speed in mm/min
         */
        void move_head_to_coordinate(const vector3i_c &coordinate, const uint16_t &speed) override;
        
        /**
         * @brief move head to coordinate
         * This function moves the uArm swift pro head to a certain cartesian location.
         *
         * @param coordinate cartesian integer coordinate for the head (XYZ)
         */
        void move_head_to_coordinate(const vector3i_c &coordinate) override;
        
        /**
         * @brief Move head to polar coordinate
         * This function moves the uArm swift pro head to a certain polar coordination.
         * 
         * @param coordinate polar coordinates, S is stretch(mm), R is rotation(degree),H is height(mm)
         * @param speed movement speed in mm/min
         */

        void move_head_to_polar_coordinate(const vector3i_c &coordinate, const uint16_t &speed);

        /**
         * @brief Rotate id motor to degree
         * This function rotates the chosen motor with his id to a certain degree.
         * 
         * @param id id of joints (0 ~ 3)
         * @param degree degree of angle (0 ~ 180)
         */
        void rotate_id_motor_to_degree(const uint8_t &id, const uint16_t &degree);

        /**
         * @brief relative displacement head
         * This function displace relative the head from his starting point with a cartesian location.
         * 
         * @param coordinate cartesian integer coordinate for the head (XYZ)
         * @param speed movement speed in mm/min
         */
        void relative_displacement_head(const vector3i_c &coordinate, const uint16_t &speed);

        /**
         * @brief relative displacement polar head
         * This function displace relative the head from his starting point with to a polar location.
         * 
         * @param coordinate polar coordinates, S is stretch(mm), R is rotation(degree),H is height(mm)
         * @param speed movement speed in mm/min
         */
        void relative_displacement_polar_head(const vector3i_c &coordinate, const uint16_t &speed);

        /**
         * @brief attach all joint motors
         * This setting function attach all the joint motors.
         */
        void attach_all_joint_motors();
        
        /**
         * @brief de/tach all joint motors
         * This setting function attach all the joint motors.
         */
        void detach_all_joint_motors();

        /**
         * @brief return cartesian coordinates by speed
         * This function wil set a time cycle of feedback, return Cartesian coordinates by debug funciton 
         * 
         * @param speed is time(seconds) 
         */
        void return_cartesian_coordinates_by_speed(const uint16_t &speed);

        /**
         * @brief attach motor by id
         * This function wil attach motor by id
         * 
         * @param id id of joints (0 ~ 3)
         */
        void attach_motor_by_id(const uint8_t &id);

        /**
         * @brief detach motor by id
         * This function wil detach motor by id
         * 
         * @param id id of joints (0 ~ 3)
         */
        void detach_motor_by_id(const uint8_t &id);
        
        /**
         * @brief check attached motor by id
         * This function wil check if the motor is attached by id
         * 
         * @param id id of joints (0 ~ 3)
         */
        void check_attached_motor_by_id(const uint8_t &id);

        /**
         * @brief set buzzer
         * This function turns on a buzzer for a chosen time with a chosen frequency
         * 
         * @param frequence frequence of buzzer (hertz)
         * @param time the amount of time the buzzer turns on (ms)
         */
        void set_buzzer(const uint16_t &frequence, const uint16_t &time);

        /**
         * @brief convert coordinates to angle of joints
         * This function convert coordinates to angle of joints,
         * return angle of joints by debug method
         * 
         * @param coordinate cartesian integer coordinate(XYZ)
         */       
        void convert_coordinates_to_angle_of_joints(const vector3i_c &coordinate);

        /**
         * @brief convert angle of joints to coordinate
         * This function Convert angle of joints to cartesian coordinates,
         * return cartesian coordinates by debug method
         * 
         * @param angle angle of the joints: vector3("B joint 0","L joint 1","R joints 2") from 0~180 degree
         */
        void convert_angle_of_joints_to_coordinates(const vector3i_c &angle);

        /**
         * @brief check posibility of coordinates cartesian polar
         * This function check if the head can reach, id 1 polar, id 0 Cartesian coordinates,
         * return ok V1 when reachable, ok V0 when unreachable
         * 
         * @param coordinate cartesian integer coordinate(XYZ) 
         * @param id 0 = cartesian , 1 = polar
         */
        void check_posibility_of_coordinates_cartesian_polar(const vector3i_c &coordinate, const uint8_t &id);

        /**
         * @brief set current position head to reference position
         * This function set the current position into the reference position
         */
        void set_current_position_head_to_reference_position();   

        /**
         * @brief get current angle of joints
         * This function wil get the current angle of joints
         */
        void get_current_angle_of_joints();

        /**
         * @brief get device name
         * This function wil get the device name
         */
        void get_device_name();

        /**
         * @brief get hardware version
         * This function wil get the hardware version
         */
        void get_hardware_version();

        /**
         * @brief get software version
         * This function wil get the software version
         */
        void get_software_version();

        /**
         * @brief get API version
         * This function wil get the API version
         */
        void get_API_version();

        /**
         * @brief get UID
         * This function wil get the UID
         */
        void get_UID();

        /**
         * @brief get angle of joint id
         * This function wil get the angle of number 0 joint (0~2)
         * 
         *  @param id id of joints (0 ~ 2)
         */
        void get_angle_of_joint_id(const uint8_t &id);

        /**
         * @brief get current coordinates
         * This function wil get current coordinates
         */
        void get_current_coordinates();

        /**
         * @brief get current polar coordinates
         * This function wil get current polar coordinates 
         */
        void get_current_polar_coordinates();

        /**
         * @brief get status power connection
         * This function wil get the status of power connection
         */
        void get_status_power_connection();

        /**
         * @brief get current status
         * This function wil check current status
         */
        void check_current_status();

        /**
         * @brief Initialization
         * This function is for actions that need to be executed at
         * initialization of the object
         *
         * @parram on_off to set the uarm on or off
         */
        void init(const uint8_t &on_off);

        /**
         * @brief debug
         * This function will write the feedback of the uarm to hwlib::cout
         */
        void debug();
    };
} // namespace r2d2::robot_arm
