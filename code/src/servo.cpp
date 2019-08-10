#include "pwm.hpp"
#include <servo.hpp>
namespace r2d2::robot_arm {

    // For servo_channel_pin and corresponding pin, look at table:
    // https://github.com/R2D2-2019/R2D2-2019/wiki/PWM_library#pin-layout
    servo_c::servo_c(int servo_channel_pin, r2d2::pwm_lib::clocks clock)
        : servo_channel(r2d2::pwm_lib::pwm_c(servo_channel_pin)) {
        servo_channel.select_frequency(freq);
        servo_channel.set_global_pwm_clock(50, clock);
    }

    void servo_c::servo_rotate(uint8_t rotation_degree, angles angle) {
        rotation = rotation_degree;
        if (angle == angles::theta) {
            pwm_duty_cycle = 150 - 0.666 * rotation;
        }
        if (angle == angles::beta) {
            pwm_duty_cycle = 120 + 0.6666 * rotation;
        }
        servo_channel.set_duty_cycle(pwm_duty_cycle);
    }

} // namespace r2d2::robot_arm
