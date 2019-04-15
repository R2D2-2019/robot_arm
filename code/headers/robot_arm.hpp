#pragma once

#include <hardware_usart.hpp>
#include <hwlib.hpp>

namespace r2d2::robot_arm {
    class robot_arm_c {
    protected:
        r2d2::hardware_usart_c usart_bus;

    public:
        robot_arm_c(r2d2::hardware_usart_c usart_bus);
        robot_arm_c(unsigned int bautrate, r2d2::uart_ports_c usart_port);
        /**
         * Virtual function
         * This function sends a command to the arm.
         *
         * @param command
         * @return boolean
         */
        virtual bool send_command(const char *command) {
            return false;
        };
        /**
         * Virtual function
         * Moves the robot arm joint [joint_id] in a given angle
         *
         */
        virtual void move_joint(int joint_id, int angle){};
        /**
         * Virtual function
         * Moves head of robot arm head/end effector towards the 3D coordinate
         * [x,y,z] The speed is default at 500 mm/min
         *
         * @param x
         * @param y
         * @param z
         * @param speed
         */
        virtual void move_head_towards(int x, int y, int z, int speed = 500){};
    };

} // namespace r2d2::robot_arm