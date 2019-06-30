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

    


    // driver code
    //uarm.init(1);
    uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i_c(100, 100, 100),90);
    //uarm.rotate_id_motor_to_degree(0,60);
    //hwlib::wait_ms(20000);
    //uarm.move_head_to_polar_coordinate(r2d2::robot_arm::vector3i_c(200, 200, 200),1000);
    // You can add an extra parameter after the vector for speed if you'd like
    // i.e. uarm.move_head_to_coordinate(r2d2::robot_arm::vector3i(100, 100,
    // 100), 500);
    return 0;
}
