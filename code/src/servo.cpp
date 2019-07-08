#include <servo.hpp>
namespace r2d2::robot_arm {
    servo_c::servo_c(r2d2::pwm_lib::pwm_c servo_channel)
        : servo_channel(servo_channel)

    {
    }

    void servo_c::servo_rotate(uint8_t rotation_degree, angles angle) {
        rotation = rotation_degree;
        if (angle == angles::theta) {
            pwm_duty_cycle = 150 - 0.666 * rotation;
            // hwlib::cout << "theta angle:" << rotation << "\n";
        }
        if (angle == angles::beta) {
            pwm_duty_cycle = 120 + 0.6666 * rotation;
            hwlib::cout << "beta" << pwm_duty_cycle << "\n";
            hwlib::cout << "beta angle:" << rotation << "\n";
        }
        // hwlib::cout << rotation << "\n";
        servo_channel.set_duty_cycle(pwm_duty_cycle);
    }

} // namespace r2d2::robot_arm
