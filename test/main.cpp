#include "coordinate_3D_c.hpp"
#include <iostream>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <iostream>

TEST_CASE("Operator==") {
    r2d2::robot_arm::coordinate_3D_c c(1, 5, 6);
    r2d2::robot_arm::coordinate_3D_c c2(1, 5, 6);
    REQUIRE(c == c2);
}

TEST_CASE("Default constructor") {
    r2d2::robot_arm::coordinate_3D_c c;
    REQUIRE(c == r2d2::robot_arm::coordinate_3D_c(0, 0, 0));
}

TEST_CASE("Constructor, one value") {
    r2d2::robot_arm::coordinate_3D_c c(5);
    REQUIRE(c == r2d2::robot_arm::coordinate_3D_c(5, 5, 5));
}

TEST_CASE("Constructor, three values") {
    r2d2::robot_arm::coordinate_3D_c c(1, 2, 3);
    REQUIRE(c == r2d2::robot_arm::coordinate_3D_c(1, 2, 3));
}

TEST_CASE("Operator + with coordinate") {
    r2d2::robot_arm::coordinate_3D_c c(1, 2, 3);
    r2d2::robot_arm::coordinate_3D_c result =
        c + r2d2::robot_arm::coordinate_3D_c(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::coordinate_3D_c(2, 4, 6));
}

TEST_CASE("Operator + with int") {
    r2d2::robot_arm::coordinate_3D_c c(1, 2, 3);
    r2d2::robot_arm::coordinate_3D_c result = c + 1;
    REQUIRE(result == r2d2::robot_arm::coordinate_3D_c(2, 3, 4));
}

TEST_CASE("Operator += with coordinate") {
    r2d2::robot_arm::coordinate_3D_c c(1, 2, 3);
    c += r2d2::robot_arm::coordinate_3D_c(3, 4, 5);
    REQUIRE(c == r2d2::robot_arm::coordinate_3D_c(4, 6, 8));
}

TEST_CASE("Operator += with int") {
    r2d2::robot_arm::coordinate_3D_c c(4, 5, 6);
    c += 3;
    REQUIRE(c == r2d2::robot_arm::coordinate_3D_c(7, 8, 9));
}

TEST_CASE("Operator++") {
    r2d2::robot_arm::coordinate_3D_c c(1, 2, 3);
    c++;
    REQUIRE(c == r2d2::robot_arm::coordinate_3D_c(2, 3, 4));
}

TEST_CASE("Operator- with coordinate") {
    r2d2::robot_arm::coordinate_3D_c c(1, 2, 3);
    r2d2::robot_arm::coordinate_3D_c result =
        c - r2d2::robot_arm::coordinate_3D_c(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::coordinate_3D_c(0, 0, 0));
}

TEST_CASE("Operator- with int") {
    r2d2::robot_arm::coordinate_3D_c c(5, 2, 3);
    r2d2::robot_arm::coordinate_3D_c result = c - 2;
    REQUIRE(result == r2d2::robot_arm::coordinate_3D_c(3, 0, 1));
}

TEST_CASE("Operator-= with coordinate") {
    r2d2::robot_arm::coordinate_3D_c c(5, 4, 3);
    c -= r2d2::robot_arm::coordinate_3D_c(1, 2, 3);
    REQUIRE(c == r2d2::robot_arm::coordinate_3D_c(4, 2, 0));
}

TEST_CASE("Operator-= with int") {
    r2d2::robot_arm::coordinate_3D_c c(5, 4, 3);
    c -= 3;
    REQUIRE(c == r2d2::robot_arm::coordinate_3D_c(2, 1, 0));
}

TEST_CASE("Operator--") {
    r2d2::robot_arm::coordinate_3D_c c(5, 4, 3);
    c--;
    REQUIRE(c == r2d2::robot_arm::coordinate_3D_c(4, 3, 2));
}

TEST_CASE("Operator/ with coordinate") {
    r2d2::robot_arm::coordinate_3D_c c(5, 4, 3);
    r2d2::robot_arm::coordinate_3D_c result =
        c / r2d2::robot_arm::coordinate_3D_c(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::coordinate_3D_c(5, 2, 1));
}

TEST_CASE("Operator/ with int") {
    r2d2::robot_arm::coordinate_3D_c c(4, 10, 20);
    r2d2::robot_arm::coordinate_3D_c result = c / 2;
    REQUIRE(result == r2d2::robot_arm::coordinate_3D_c(2, 5, 10));
}

TEST_CASE("Operator/= with coordinate") {
    r2d2::robot_arm::coordinate_3D_c c(5, 10, 20);
    c /= r2d2::robot_arm::coordinate_3D_c(5, 2, 2);
    REQUIRE(c == r2d2::robot_arm::coordinate_3D_c(1, 5, 10));
}

TEST_CASE("Operator/= with int") {
    r2d2::robot_arm::coordinate_3D_c c(10, 100, 200);
    c /= 2;
    REQUIRE(c == r2d2::robot_arm::coordinate_3D_c(5, 50, 100));
}
