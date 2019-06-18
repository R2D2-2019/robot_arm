#pragma once
#include <cmath>

namespace r2d2::robot_arm {

    class calculate_inverse_kinematics_c {
    private
        uint16_t arm_lengt1, arm_lengt2;
        uint16_t position_end_effector;
        uint16_t angle_aplha, angle_beta;

    public:
        /**
         * Robot arm constructor, needs an usart bus for communication
         */
        calculate_inverse_kinematics(uint16_t arm_lengt1,
        uint16_t arm_lengt2));
        /**
         * @brief
         * This function calculates the angles of the robot arm when a
         *position is given.
         *
         *@param coordinate
         *
         */
        void set_position_end_effector(vector3i_c coordinate);
        /**
         * @brief
         * get the angle of alhpa after it calcualted by the
         *set_position_end_effector function
         *
         *@return angle of axis alpha
         *
         */
        uint16_t get_angle_alpha();
        /**
         * @brief
         * get the angle of beta after it calcualted by the
         *set_position_end_effector function
         *
         *@return angle of axis beta
         *
         */
        uint16_t get_angle_beta();
        /**
         * @brief
         * get the vector cordinates of the end effector
         *
         *@return coordinates of end effector
         *
         */
        vector3i_c get_position_end_effector();
    };

} // namespace r2d2::robot_arm
