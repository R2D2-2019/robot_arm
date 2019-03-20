//
// Created by Slimmerik on 20/03/2019.
//
#include "../headers/test_arm.h"


void r2d2::robot_arm::test_arm::move_head_to_coordinate_impl(const uint16_t &x, const uint16_t &y, const uint16_t &z) {
//    if(in_range(x,y,z)) {
//        hwlib::cout << " " << x << y << z;
//    }
}

void r2d2::robot_arm::test_arm::rotate_head_impl(const uint16_t &r) {
    // Default implementation
    hwlib::cout << " " << r;
}

//bool r2d2::robot_arm::test_arm::in_range(const uint16_t &x, const uint16_t &y, const uint16_t &z){
//    if(x >= max_range_x || x <= min_range_x){
//        return false;
//    }
//    if(y >= max_range_y || y <= min_range_y){
//        return false;
//    }
//    if(z >= max_range_z || z <= min_range_z){
//        return false;
//    }
//    return true;
//}