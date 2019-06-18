#pragma once
#include <hwlib.hpp>
namespace r2d2::robot_arm {
    class servo {

    private
        uint16_t pwm_lenght;
        uint16_t rotation;

    public:
        /**
         * @brief
         *servo class constructor
         */
        servo();
        /**
         *brief
         * rotates the servo to a new position
         *param degree_of_rotation new angle of the rotation
         */
        servo_rotate(uint16_t degree_of_rotation);
    };

} // namespace r2d2::robot_arm
