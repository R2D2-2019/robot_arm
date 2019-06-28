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
         * Robot arm constructor, needs an usart bus for communication
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
         * Move arm's head to 3D coordinate
         * Moves head of robot arm head/end effector towards the 3D coordinate
         * [x,y,z] The speed is default at 500 mm/min
         *
         * @param coordinate 3D integer coordinate for the head
         * @param speed movement speed in mm/min
         */
        void move_head_to_coordinate(const vector3i_c &coordinate, const uint16_t &speed) override;
        /**
         * This function moves the uArm swift pro head to a certain 3d location.
         *
         * @param coordinate
         */
        void move_head_to_coordinate(const vector3i_c &coordinate) override;
        
        /**
         * This function moves the uArm swift pro head to a certain polar coordination.
         * 
         * @param coordinate polar coordinates, S is stretch(mm), R is rotation(degree),H is height(mm)
         * @param speed movement speed in mm/min
         */

        void move_head_to_polar_coordinate(const vector3i_c &coordinate, const uint16_t &speed);
        
        void rotate_id_motor_to_degree(const uint8_t &id, const uint16_t &degree);

        void relative_displacement_head(const vector3i_c &coordinate, const uint16_t &speed);

        void relative_displacement_polar_head(const vector3i_c &coordinate, const uint16_t &speed);

        void attach_all_joint_motors();
        
        void detach_all_joint_motors();

        void return_cartesian_coordinates_by_speed(const uint16_t &speed);

        void attach_motor_by_id(const uint8_t &id);

        void detach_motor_by_id(const uint8_t &id);

        void check_attached_motor_by_id(const uint8_t &id);

        void set_buzzer(const uint16_t &frequence, const uint16_t &time);

        void convert_coordinates_to_angle_of_joints(const vector3i_c &coordinate);

        void convert_angle_of_joints_to_coordinates(const vector3i_c &angle);
        /**
         * @brief Initialization function
         * This function is for actions that need to be executed at
         * initialization of the object
         *
         */
        void init(const uint8_t &on_off);

        void debug();
    };
} // namespace r2d2::robot_arm
