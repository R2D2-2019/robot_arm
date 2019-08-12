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
        uint8_t last_degree = 0;
        angles last_angle = angles::theta;

    public:
        /**
         * @brief
         * Servo class constructor.
         * @detailed
         * Create a servo object to control a servo with. It expects a
         * servo_channel_pin.
         * @param
         * Int servo_channel_pin corresponds to a pin on the arduino. Find the
         * pin table here:
         * https://github.com/R2D2-2019/R2D2-2019/wiki/PWM_library#pin-layout
         */
        servo_c(uint8_t servo_channel_pin,
                r2d2::pwm_lib::clocks clock = r2d2::pwm_lib::clocks::CLOCKA);

        /**
         * @brief
         * Rotates the servo to a new angle.
         * @param uint8_t degree_of_rotation - new angle to set the servo at.
         * @param angles angle - How the servo rotates.
         */
        void servo_rotate(uint8_t degree_of_rotation, angles angle);

        /**
         * @brief
         * Get the last given degrees the servo rotated to.
         * @return uint8_t last_degrees - last given angle the servo rotated to.
         */
        uint8_t get_last_degree();

        /**
         * @brief
         * Get the last angle used for rotating the servo.
         * @return angles last_angle - the angle last used for rotating the
         * servo.
         */
        angles get_last_angle();
    };

} // namespace r2d2::robot_arm
