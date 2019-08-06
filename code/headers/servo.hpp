#pragma once
#include <hwlib.hpp>
#include <pwm.hpp>
namespace r2d2::robot_arm {
    enum class angles { theta, beta };

    class servo_c {

    private:
        uint8_t pwm_duty_cycle;
        uint16_t rotation;
        r2d2::pwm_lib::pwm_c servo_channel;
        r2d2::pwm_lib::frequencies freq = r2d2::pwm_lib::frequencies::f_320hz; 

    public:
        /**
         * @brief
         * servo class constructor
         * @detailed
         * create a servo object to control a servo with. It expects a servo_channel_pin.
         * @param
         * int servo_channel_pin corresponds to a pin on the arduino. Find the pin table here: https://github.com/R2D2-2019/R2D2-2019/wiki/PWM_library#pin-layout
         */
        servo_c(int servo_channel_pin, r2d2::pwm_lib::clocks clock = r2d2::pwm_lib::clocks::CLOCKA);
        /**
         *brief
         * rotates the servo to a new position
         *param degree_of_rotation new angle of the rotation
         */
        void servo_rotate(uint8_t degree_of_rotation, angles angle);
    };

} // namespace r2d2::robot_arm
