#include <../headers/test_arm_c.hpp>


void r2d2::robot_arm::test_arm_c::move_head_to_coordinate_impl(const int16_t &x, const int16_t &y, const int16_t &z) {
    if (in_range(x, y, z)) {
        hwlib::cout << "checks out move head " << "x " << x << "y " << y << "z " << z << "\n";
    }
}

void r2d2::robot_arm::test_arm_c::rotate_head_impl(const uint16_t &r) {
    if (in_range(r)) {
        hwlib::cout << "checks out rotate head " << r << "\n";
    }
}

bool r2d2::robot_arm::test_arm_c::in_range(const int16_t &x, const int16_t &y, const int16_t &z) {
    hwlib::cout << x << " " << y << " " << z << " " << max_range_x << " " << max_range_y << " " << max_range_z << " "
                << min_range_x << " " << min_range_y << " " << min_range_z << "\n";

    if (x >= max_range_x && x <= min_range_x) {
        hwlib::cout << "nope x " << x << "\n";
        return false;
    }
    if (y >= max_range_y && y <= min_range_y) {
        hwlib::cout << "nope y " << y << "\n";
        return false;
    }
    if (z >= max_range_z && z <= min_range_z) {
        hwlib::cout << "nope z " << z << "\n";
        return false;
    }
    return true;
}

bool r2d2::robot_arm::test_arm_c::in_range(const uint16_t &head_position) {
    hwlib::cout << head_position << " " << max_rotation_degrees << " " << min_rotation_degrees << "\n";

    if (head_position >= max_rotation_degrees || head_position <= min_rotation_degrees) {
        hwlib::cout << "nope r " << head_position << "\n";
        return false;
    }
    return true;
}