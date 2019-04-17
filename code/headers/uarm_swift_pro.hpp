#pragma once

#include <hwlib.hpp>
#include <robot_arm_interface.hpp>
#include <vector3.hpp>
#include <hardware_usart.hpp>
#include <cstring>
#include <uarm_gcode_generator.hpp>

/**
 * Class uArm_swift_pro provides a implementation for uArm swift pro.
 */
namespace r2d2::robot_arm {
    class uarm_swift_pro_c : public robot_arm_interface_c {
    protected:

        const uint16_t default_speed = 1000;

    private:
        uarm_gcode_generator_c<50> gcode_generator;
        hardware_usart_c usart_bus ;
    public:

        /**
         * Robot arm constructor, needs an usart bus for communication
         */
        uarm_swift_pro_c(const r2d2::hardware_usart_c &usart_bus);
        /**
         * robot arm constructor, creates a usart bus from the bautrate and port
         **/
        uarm_swift_pro_c(unsigned int &bautrate, r2d2::uart_ports_c &usart_port);
        /**
         * Destroy the robot arm object
         *
         */
        ~uarm_swift_pro_c(){};

        /**
       * @brief Initialization function
       * This function is for actions that need to be executed at
       * initialization of the object
       *
       */
        void init();
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
         * Move specific joint of the arm
         * Moves the robot arm joint [joint_id] in a given angle
         *
         */
        void move_joint(const int &joint_id, const int &angle);
        /**
         * Move arm's head to 3D coordinate
         * Moves head of robot arm head/end effector towards the 3D coordinate
         * [x,y,z] The speed is default at 500 mm/min
         *
         * @param coordinate 3D integer coordinate for the head
         * @param speed movement speed in mm/min
         */
        void move_head_to_coordinate(const vector3i_c &coordinate,
                                             const uint16_t speed) override;
        /**
         * This function moves the uArm swift pro head to a certain 3d location.
         *
         * @param coordinate
         */
        void move_head_to_coordinate(const vector3i_c &coordinate) override;
        /**
         * This function rotates the head of the 4dof diy robot arm.
         *
         * @param rotation
         */
        void rotate_head(const int16_t &rotation) override;
    };
} // namespace r2d2::robot_arm
