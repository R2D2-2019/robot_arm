#pragma once
#include <cmath>
#include <hwlib.hpp>
#include <vector3.hpp>
#define PI 3.14159265
namespace r2d2::robot_arm {

    class calculate_inverse_kinematics_c {
    private:
        // Lengths of the arms.
        uint16_t arm_length1, arm_length2;
        // Position of the end effector.
        vector3i_c position_end_effector;
        // Angleles.
        uint16_t angle_aplha, angle_beta, angle_phi, angle_theta;

    public:
        /**
         * @brief
         * Calculate_inverse_kinematics_c constructor
         * @detailed
         * Creates a calculate_inverse_kinematics_c object. This can be used to
         * calculate angles for a robot arm with 2 joints.
         * @param uint16_t arm_length1 - length of the bottem arm in mm.
         * @param uint16_t arm_length1 - length of the top arm in mm.
         */
        calculate_inverse_kinematics_c(uint16_t arm_length1,
                                       uint16_t arm_length2);
        /**
         * @brief
         * This function calculates the angles of the robot arm when a
         * Position is given.
         * @detailed
         * This function calculates the angles for the servo's that control the
         * 2 joints of the robot arm. The results get saved within this class.
         * @param vector3i_c coordinate - The coordinates where the end effector
         * has to go. Int x and int y areused for the position. Int z is not
         * used.
         */
        void set_position_end_effector(vector3i_c coordinate);

        /**
         * @brief
         * Get the angle of theta.
         * @detailed
         * Get the angle of theta. This angle can be calculated using the
         * set_position_end_effector() method from this class.
         * @return uint16_t angle - angle of axis theta.
         */
        uint16_t get_angle_theta();

        /**
         * @brief
         * Get the angle of beta.
         * @detailed
         * Get the angle of beta. This angle can be calculated using the
         * set_position_end_effector() method from this class.
         * @return uint16_t angle - angle of axis beta.
         */
        uint16_t get_angle_beta();

        /**
         * @brief
         * Get the vector coordinates of the end effector.
         * @detailed
         * Get the coordinates of the end effector. Tot garranteed to work when
         * the arm has been controlled outside this class.
         * @return vector3i_c coordinates - coordinates of the end effector.
         */
        vector3i_c get_position_end_effector();
    };

} // namespace r2d2::robot_arm
