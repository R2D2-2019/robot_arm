#include <vector3.hpp>
#include <hardware_usart.hpp>
#include <hwlib.hpp>
#include <comm.hpp>
#include <uarm_swift_pro.hpp>
#include <mock_bus.hpp>

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);
    auto usart = r2d2::usart::hardware_usart_c<r2d2::usart::usart0>(115200);
    
    r2d2::comm_c comm;
    
    r2d2::robot_arm::uarm_swift_pro_c uarm(usart, comm);

    uarm.switch_uart2_uart0();
    


    // driver code
    uarm.attach_all_joint_motors();
    uarm.init(1);
    hwlib::wait_ms(500);
    //hwlib::cout << "command 1" << hwlib::endl;
    //uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(190, 100, 100), 200);
    //uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(100, 100, 100), 200);
    // hwlib::wait_ms(2000);
    //uarm.init(1);
    //hwlib::cout << "command 2" << hwlib::endl;



    //----------------------------------DEMO----------------------------------------//
    // DOTS
    // int x = 150;
    // int y = 50;
    // for(int i = 0; i < 10; i++){
    //     x = 150;
    //     for (int i = 0; i < 10; i++){
    //         x += 10;
    //         uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(x, y, 75), 3000);
    //         uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(x, y, 50), 3000);
    //         uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(x, y, 75), 3000);
    //     }
    //     y -= 10;
    //     //for(int i = 200; i > 0; i -= 10){
    //     //}

    // }
    uarm.gripper_close_open();
    hwlib::wait_ms(1000);
    //----------------------------------DEMO----------------------------------------//

    //smile:)
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(190, 50, 75), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(190, 50, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(170, 30, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(170, -20, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(190, -40, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(190, -40, 75), 3000);


    // Eye see you
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, 30, 75), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, 30, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, 10, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, 10, 75), 3000);

    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, 0, 75), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, 0, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, -20, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, -20, 75), 3000);

    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, 20, 75), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, 20, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, 20, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, 20, 75), 3000);

    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, -10, 75), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(200, -10, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, -10, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, -10, 75), 3000);

    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, 30, 75), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, 30, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, 10, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, 10, 75), 3000);

    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, 0, 75), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, 0, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, -20, 50), 3000);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(240, -20, 75), 3000);

    //----------------------------------TEST---------------------------------------//

    // uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(130, 90, 50));
    // hwlib::wait_ms(2000);
    // uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(170, 90, 50));
    // hwlib::wait_ms(2000);
    // uarm.move_head_to_polar_coordinate(r2d2::robot_arm::vector3i_c(100, 90, 50), 1000);
    // hwlib::wait_ms(2000);
    // uarm.rotate_id_motor_to_degree(0,90);
    // uarm.rotate_id_motor_to_degree(1,40);
    // uarm.rotate_id_motor_to_degree(2,90);
    // hwlib::wait_ms(2000);
    // uarm.relative_displacement_head(r2d2::robot_arm::vector3i_c(10, 10, 10), 1000);
    // hwlib::wait_ms(2000);
    // uarm.relative_displacement_polar_head(r2d2::robot_arm::vector3i_c(10, 10, 10), 1000);
    // uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(132, 30, 105), 1000);
    // hwlib::wait_ms(10000);
    // uarm.detach_all_joint_motors();
    // hwlib::wait_ms(10000);
    // uarm.attach_all_joint_motors();
    // hwlib::wait_ms(5000);
    // uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(150, 90, 50), 1000);
    // hwlib::wait_ms(10000);
    // uarm.detach_motor_by_id(2);
    // hwlib::wait_ms(10000);
    // uarm.attach_motor_by_id(2);
    // hwlib::wait_ms(5000);
    // uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(100, 90, 50), 1000);
    // hwlib::wait_ms(2000);
    // uarm.set_buzzer(1000,1000);
    // hwlib::wait_ms(10000);
    
    //uarm.rotate_id_motor_to_degree(0,60);
    //hwlib::wait_ms(20000);
    //uarm.move_head_to_polar_coordinate(r2d2::robot_arm::vector3i_c(200, 200, 200),1000);
    // You can add an extra parameter after the vector for speed if you'd like
    // i.e. uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i(100, 100,
    // 100), 500);
    return 0;
}
