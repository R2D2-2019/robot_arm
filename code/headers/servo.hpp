#pragma once
//#include <calculate_inverse_kinematics.hpp>
#include <hwlib.hpp>
#include <pwm.hpp>
namespace r2d2::robot_arm {
    enum class angles { theta, beta };

    class servo_c {

    private:
        uint8_t pwm_duty_cycle;
        uint16_t rotation;
        r2d2::pwm_lib::pwm_c servo_channel;

    public:
        /**
         * @brief
         *servo class constructor
         */
        servo_c(r2d2::pwm_lib::pwm_c servo_channel);
        /**
         *brief
         * rotates the servo to a new position
         *param degree_of_rotation new angle of the rotation
         */
        void servo_rotate(uint8_t degree_of_rotation, angles angle);
    };

} // namespace r2d2::robot_arm
