#pragma once

#include <hardware_usart.hpp>
#include <hwlib.hpp>
#include <vector3.hpp>

namespace r2d2::robot_arm {
    class robot_arm_c {
    protected:
        r2d2::hardware_usart_c usart_bus;

    public:
        /**
         * Robot arm constructor, needs an usart bus for communication
         */
        robot_arm_c(const r2d2::hardware_usart_c &usart_bus);
        /**
         * robot arm constructor, creates a usart bus from the bautrate and port
         **/
        robot_arm_c(unsigned int &bautrate, r2d2::uart_ports_c &usart_port);
        /**
         * Destroy the robot arm object
         *
         */
        virtual ~robot_arm_c(){};
        /**
         * @brief Initialization function
         * This function is for actions that need to be executed at
         * initialization of the object
         *
         */
        virtual void init(){};
        /**
         * @brief Check connection
         * Function to check whether the connection with the arm is right or not
         *
         * @return true means connection is right
         * @return false means connection is wrong
         */
        virtual bool check_connection() = 0;
        /**
         * @brief Sending command to arm
         * Sends false as default
         *
         * @param command
         * @return false when something went wrong with sending
         * @return true when command correctly sent
         */
        virtual bool send_command(const char *command) = 0;
        /**
         * Move specific joint of the arm
         * Moves the robot arm joint [joint_id] in a given angle
         *
         */
        virtual void move_joint(const int &joint_id, const int &angle) = 0;
        /**
         * Move arm's head to 3D coordinate
         * Moves head of robot arm head/end effector towards the 3D coordinate
         * [x,y,z] The speed is default at 500 mm/min
         *
         * @param coordinate 3D integer coordinate for the head
         * @param speed movement speed in mm/min
         */
        virtual void move_head_to_coordinate(const vector3i_c &coordinate,
                                             const int speed = 500) = 0;
    };

} // namespace r2d2::robot_arm