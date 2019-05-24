#include <dof4_diy.hpp>
#include <hardware_usart.hpp>
#include <hwlib.hpp>
#include <robot_arm_interface.hpp>
#include <uarm_swift_pro.hpp>
#include <pwm.hpp>
#include <hardware_usart.hpp>

using namespace r2d2::robot_arm;

int main() {
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(1000);

    auto pwm1 = R2D2::pwm_lib::pwm_c(7);
    // auto pwm2 = R2D2::pwm_lib::pwm_c(1);

    pwm1.set_global_pwm_clock(50, R2D2::pwm_lib::clocks::CLOCKA);

    pwm1.select_frequency(R2D2::pwm_lib::frequencies::CLOCKA);
    // pwm1.set_duty_cycle(127);
    pwm1.set_duty_cycle(0);
    hwlib::wait_ms(1000);

    // int m = 5;
    char c = 'A';
    int rest = 0;
    while (true){
        hwlib::cout << rest << "\n";
        pwm1.set_duty_cycle(rest);
        hwlib::wait_ms(200);

        hwlib::cin >> c;
        if (c == '[') rest --;
        if (c == ']') rest ++;
    };
}