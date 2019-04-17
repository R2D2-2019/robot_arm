#include <dof4_diy.hpp>
#include <hwlib.hpp>
#include <robot_arm_interface.hpp>
#include <uarm_swift_pro.hpp>
#include <hardware_usart.hpp>




using namespace r2d2::robot_arm;

int main() {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    vector3i_c v(100,100,100);

    r2d2::uart_ports_c uart_port_one = r2d2::uart_ports_c::uart1;

    auto usart_bus_uarm = r2d2::hardware_usart_c(9600, uart_port_one);

    uarm_swift_pro_c uarm(usart_bus_uarm);

    uarm.init();
    hwlib::wait_ms(1000);
    uarm.move_head_to_coordinate(v);
    hwlib::cout << "done";

}