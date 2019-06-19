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
    protected:
        const uint16_t default_speed = 1000;

    private:
        using usart_c = r2d2::usart::usart_connection_c;
        uarm_gcode_generator_c<50> gcode_generator;
        usart_c &usart_bus;

    public:
        /**
         * Robot arm constructor, needs an usart bus for communication
         */
        uarm_swift_pro_c(usart_c &usart_bus);

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
         * @brief
         * Move specific joint of the arm
         * Moves the robot arm joint [joint_id] in a given angle
         *
         * @param joint_id the id of the joint that needs to be moved
         * @param angle the angel at which the joint needs to be
         */
        void move_joint(const int &joint_id, const int &angle);
        /**
         * @brief
         * Move arm's head to 3D coordinate
         * Moves head of robot arm head/end effector towards the 3D coordinate
         * [x,y,z] The speed is default at 500 mm/min
         *
         * @param coordinate 3D integer coordinate for the head
         * @param speed movement speed in mm/min
         */
        void move_head_to_coordinate(const vector3i_c &coordinate,
                                     uint16_t speed) override;
        /**
         * @brief
         * This function moves the uArm swift pro head to a certain 3d location.
         *
         * @param coordinate the coordinate the head needs to move to
         */
        void move_head_to_coordinate(const vector3i_c &coordinate) override;
        /**
         * @brief
         * This function rotates the head of the 4dof diy robot arm.
         *
         * @param rotation The rotation the head needs to move
         */
        void rotate_head(int16_t rotation) override;
    };
} // namespace r2d2::robot_arm
