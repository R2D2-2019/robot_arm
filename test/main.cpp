#include "coordinate_3D_c.hpp"
#include "uArm_gcode_generator_c.hpp"
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>

TEST_CASE("Appending") {
    r2d2::robot_arm::uArm_gcode_generator_c generator;
    char buf[100] = "test";
    generator.append(buf, " appending works!\n");

    REQUIRE(strcmp(buf, "test appending works!"));
}

TEST_CASE("Appending in front") {
    r2d2::robot_arm::uArm_gcode_generator_c generator;
    char buf[100] = "testing";
    generator.append_front(buf, "Does it work? We're ");

    REQUIRE(strcmp(buf, "Does it work? We're testing"));
}
