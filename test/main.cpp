#include "uarm_gcode_generator_c.hpp"
#include "vector3_c.hpp"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include <catch.hpp>


TEST_CASE("Appending") {
    r2d2::robot_arm::uarm_gcode_generator_c<100> generator;
    generator.append("a");
    generator.append("b");
    REQUIRE(std::strcmp(generator.get_buffer(), "ab") == 0); // std::strcmp will not be needed later for debug only
}

TEST_CASE("Appending front") {
    r2d2::robot_arm::uarm_gcode_generator_c<100> generator;
    generator.append("123");
    generator.append_front("abcd");
    REQUIRE(std::strcmp(generator.get_buffer(), "abcd123") == 0); // std::strcmp will not be needed later for debug only
}

TEST_CASE("Converting vector to gcode command") {
    r2d2::robot_arm::uarm_gcode_generator_c<100> generator;
    generator.coordinate_to_gcode(r2d2::robot_arm::vector3i_c(1, 2, 3), 200);
    std::cout << generator.get_buffer() << std::endl;
    REQUIRE(std::strcmp(generator.get_buffer(), "#n G0 X1 Y2 Z3 F200\n") == 0); // std::strcmp will not be needed later for debug only
}

TEST_CASE("Operator==") {
    r2d2::robot_arm::vector3i_c c(1.f, 5.f, 6.f);
    r2d2::robot_arm::vector3i_c c2(1.f, 5.f, 6.f);
    REQUIRE(c == c2);
}

TEST_CASE("Default constructor") {
    r2d2::robot_arm::vector3i_c c;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(0, 0, 0));
}

TEST_CASE("Constructor, one value") {
    r2d2::robot_arm::vector3i_c c(5);
    REQUIRE(c == r2d2::robot_arm::vector3i_c(5, 5, 5));
}

TEST_CASE("Constructor, three values") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    REQUIRE(c == r2d2::robot_arm::vector3i_c(1, 2, 3));
}

TEST_CASE("Operator + with coordinate") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    r2d2::robot_arm::vector3i_c result =
        c + r2d2::robot_arm::vector3i_c(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::vector3i_c(2, 4, 6));
}

TEST_CASE("Operator + with test_data_type") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    r2d2::robot_arm::vector3i_c result = c + 1;
    REQUIRE(result == r2d2::robot_arm::vector3i_c(2, 3, 4));
}

TEST_CASE("Operator += with coordinate") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    c += r2d2::robot_arm::vector3i_c(3, 4, 5);
    REQUIRE(c == r2d2::robot_arm::vector3i_c(4, 6, 8));
}

TEST_CASE("Operator += with test_data_type") {
    r2d2::robot_arm::vector3i_c c(4, 5, 6);
    c += 3;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(7, 8, 9));
}

TEST_CASE("Operator++") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    c++;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(2, 3, 4));
}

TEST_CASE("Operator- with coordinate") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    r2d2::robot_arm::vector3i_c result =
        c - r2d2::robot_arm::vector3i_c(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::vector3i_c(0, 0, 0));
}

TEST_CASE("Operator- with test_data_type") {
    r2d2::robot_arm::vector3i_c c(5, 2, 3);
    r2d2::robot_arm::vector3i_c result = c - 2;
    REQUIRE(result == r2d2::robot_arm::vector3i_c(3, 0, 1));
}

TEST_CASE("Operator-= with coordinate") {
    r2d2::robot_arm::vector3i_c c(5, 4, 3);
    c -= r2d2::robot_arm::vector3i_c(1, 2, 3);
    REQUIRE(c == r2d2::robot_arm::vector3i_c(4, 2, 0));
}

TEST_CASE("Operator-= with test_data_type") {
    r2d2::robot_arm::vector3i_c c(5, 4, 3);
    c -= 3;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(2, 1, 0));
}

TEST_CASE("Operator--") {
    r2d2::robot_arm::vector3i_c c(5, 4, 3);
    c--;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(4, 3, 2));
}

TEST_CASE("Operator/ with coordinate") {
    r2d2::robot_arm::vector3i_c c(5, 4, 3);
    r2d2::robot_arm::vector3i_c result =
        c / r2d2::robot_arm::vector3i_c(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::vector3i_c(5, 2, 1));
}

TEST_CASE("Operator/ with test_data_type") {
    r2d2::robot_arm::vector3i_c c(4, 10, 20);
    r2d2::robot_arm::vector3i_c result = c / 2;
    REQUIRE(result == r2d2::robot_arm::vector3i_c(2, 5, 10));
}

TEST_CASE("Operator/= with coordinate") {
    r2d2::robot_arm::vector3i_c c(5, 10, 20);
    c /= r2d2::robot_arm::vector3i_c(5, 2, 2);
    REQUIRE(c == r2d2::robot_arm::vector3i_c(1, 5, 10));
}

TEST_CASE("Operator/= with test_data_type") {
    r2d2::robot_arm::vector3i_c c(10, 100, 200);
    c /= 2;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(5, 50, 100));
}
