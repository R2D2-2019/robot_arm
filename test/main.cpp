#include <uarm_gcode_generator.hpp>
#include <uarm_swift_pro.hpp>
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <test_usart.hpp>
#include <mock_bus.hpp>

TEST_CASE("Appending gone wrong!", "Testing generator") {
    r2d2::robot_arm::uarm_gcode_generator_c<2> generator;
    generator.append("a");
    generator.append("b");
    REQUIRE(std::strcmp(generator.get_buffer(), "a") == 0);
}

TEST_CASE("Requesting size", "Testing generator") {
    r2d2::robot_arm::uarm_gcode_generator_c<10> generator;
    generator.append("a");
    generator.append_front("b");
    REQUIRE(generator.length() == 2);
}

TEST_CASE("Appending", "Testing generator") {
    r2d2::robot_arm::uarm_gcode_generator_c<100> generator;
    generator.append("a");
    generator.append("b");
    REQUIRE(std::strcmp(generator.get_buffer(), "ab") ==
            0); // std::strcmp will not be needed later for debug only
}

TEST_CASE("Appending front", "Testing generator") {
    r2d2::robot_arm::uarm_gcode_generator_c<100> generator;
    generator.append("123");
    generator.append_front("abcd");
    REQUIRE(std::strcmp(generator.get_buffer(), "abcd123") ==
            0); // std::strcmp will not be needed later for debug only
}

TEST_CASE("Converting vector to gcode command", "Testing generator") {
    r2d2::robot_arm::uarm_gcode_generator_c<100> generator;
    generator.coordinate_to_gcode(r2d2::robot_arm::vector3i_c(1, 2, 3), 200);
    REQUIRE(std::strcmp(generator.get_buffer(), "#1 G0 X1 Y2 Z3 F200\n") ==
            0); // std::strcmp will not be needed later for debug only
}

TEST_CASE("Operator==", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(1.f, 5.f, 6.f);
    r2d2::robot_arm::vector3i_c c2(1.f, 5.f, 6.f);
    REQUIRE(c == c2);
}

TEST_CASE("Default constructor", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(0, 0, 0));
}

TEST_CASE("Constructor, one value", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(5);
    REQUIRE(c == r2d2::robot_arm::vector3i_c(5, 5, 5));
}

TEST_CASE("Constructor, three values", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    REQUIRE(c == r2d2::robot_arm::vector3i_c(1, 2, 3));
}

TEST_CASE("Operator + with coordinate", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    r2d2::robot_arm::vector3i_c result =
        c + r2d2::robot_arm::vector3i_c(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::vector3i_c(2, 4, 6));
}

TEST_CASE("Operator + with test_data_type", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    r2d2::robot_arm::vector3i_c result = c + 1;
    REQUIRE(result == r2d2::robot_arm::vector3i_c(2, 3, 4));
}

TEST_CASE("Operator += with coordinate", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    c += r2d2::robot_arm::vector3i_c(3, 4, 5);
    REQUIRE(c == r2d2::robot_arm::vector3i_c(4, 6, 8));
}

TEST_CASE("Operator += with test_data_type", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(4, 5, 6);
    c += 3;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(7, 8, 9));
}

TEST_CASE("Operator++", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    c++;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(2, 3, 4));
}

TEST_CASE("Operator- with coordinate", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(1, 2, 3);
    r2d2::robot_arm::vector3i_c result =
        c - r2d2::robot_arm::vector3i_c(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::vector3i_c(0, 0, 0));
}

TEST_CASE("Operator- with test_data_type", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(5, 2, 3);
    r2d2::robot_arm::vector3i_c result = c - 2;
    REQUIRE(result == r2d2::robot_arm::vector3i_c(3, 0, 1));
}

TEST_CASE("Operator-= with coordinate", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(5, 4, 3);
    c -= r2d2::robot_arm::vector3i_c(1, 2, 3);
    REQUIRE(c == r2d2::robot_arm::vector3i_c(4, 2, 0));
}

TEST_CASE("Operator-= with test_data_type", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(5, 4, 3);
    c -= 3;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(2, 1, 0));
}

TEST_CASE("Operator--", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(5, 4, 3);
    c--;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(4, 3, 2));
}

TEST_CASE("Operator * with vector", "Testing vector3i") {
    r2d2::robot_arm::vector3_c c(1, 2, 3);
    r2d2::robot_arm::vector3_c result = c * r2d2::robot_arm::vector3_c(3, 2, 1);
    REQUIRE(result == r2d2::robot_arm::vector3_c(3, 4, 3));
}

TEST_CASE("Operator * with type", "Testing vector3i") {
    r2d2::robot_arm::vector3_c c(1, 2, 3);
    r2d2::robot_arm::vector3_c result = c * 3;
    REQUIRE(result == r2d2::robot_arm::vector3_c(3, 6, 9));
}

TEST_CASE("Operator *= with vector", "Testing vector3i") {
    r2d2::robot_arm::vector3_c c(1, 2, 3);
    c *= r2d2::robot_arm::vector3_c(3, 3, 3);
    REQUIRE(c == r2d2::robot_arm::vector3_c(3, 6, 9));
}

TEST_CASE("Operator *= with type", "Testing vector3i") {
    r2d2::robot_arm::vector3_c c(1, 2, 3);
    c *= 5;
    REQUIRE(c == r2d2::robot_arm::vector3_c(5, 10, 15));
}

TEST_CASE("Operator/ with coordinate", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(5, 4, 3);
    r2d2::robot_arm::vector3i_c result =
        c / r2d2::robot_arm::vector3i_c(1, 2, 3);
    REQUIRE(result == r2d2::robot_arm::vector3i_c(5, 2, 1));
}

TEST_CASE("Operator/ with test_data_type", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(4, 10, 20);
    r2d2::robot_arm::vector3i_c result = c / 2;
    REQUIRE(result == r2d2::robot_arm::vector3i_c(2, 5, 10));
}

TEST_CASE("Operator/= with coordinate", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(5, 10, 20);
    c /= r2d2::robot_arm::vector3i_c(5, 2, 2);
    REQUIRE(c == r2d2::robot_arm::vector3i_c(1, 5, 10));
}

TEST_CASE("Operator/= with test_data_type", "Testing vector3i") {
    r2d2::robot_arm::vector3i_c c(10, 100, 200);
    c /= 2;
    REQUIRE(c == r2d2::robot_arm::vector3i_c(5, 50, 100));
}

TEST_CASE("process function", "[canbus]"){
    r2d2::mock_comm_c comm;

    auto usart = r2d2::usart::test_usart_c();

    comm.listen_for_frames({r2d2::frame_type::ALL});

    REQUIRE(comm.accepts_frame(r2d2::frame_type::ROBOT_ARM));

    r2d2::robot_arm::uarm_swift_pro_c uarm(usart, comm);


    r2d2::frame_robot_arm_s frame;

    frame.x = 8;
    frame.y = 200;
    frame.z = 200;
    frame.speed = 300;

    auto data2 = comm.create_frame<r2d2::frame_type::ROBOT_ARM>(frame);
    
    comm.accept_frame(data2);

    uarm.process();


}