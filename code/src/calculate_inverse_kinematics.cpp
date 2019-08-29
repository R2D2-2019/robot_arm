#include <calculate_inverse_kinematics.hpp>
#include "hwlib.hpp"


namespace r2d2::robot_arm {

    calculate_inverse_kinematics_c::calculate_inverse_kinematics_c(
        uint16_t arm_length1, uint16_t arm_length2)
        : arm_length1(arm_length1), arm_length2(arm_length2) {
    }

    //based on the math from this video: https://www.youtube.com/watch?v=RH3iAmMsolo

    void calculate_inverse_kinematics_c::set_position_end_effector(vector3i_c coordinate) {
        //setting the x and y and correcting with 80. This has to be changed because negative values are not supported.
        float x = coordinate.x-80;
        float y = coordinate.y-80;

        //set arm lengths
        float l1 = arm_length1;
        float l2 = arm_length2;

        
        float temp = pow(x, 2)+pow(y,2)-pow(l1, 2)-pow(l2, 2);
        temp /= 2*l1*l2;
        float q2 = acos(temp);

        hwlib::cout << "q2: " << int(q2*10) << "\n";

        temp = l2*sin(q2);
        temp /= l1 + l2*cos(q2);
        float q1 = atan(y/x) - atan(temp);

        // float q1 = atan(y/x) - atan( (l2*sin(q2) / (l1 + l2*cos(q2) ) ));

        hwlib::cout << "q1: " << int(q1*10) << "\n";

        // angle_beta = q2*57.2957795;  
        angle_beta = 180-(q2*57.2957795);  

        if(q1*57.2957795 < 0){
            angle_theta = (q1*57.2957795) * -1;
            angle_theta = 180-angle_theta;
        } else {
            angle_theta = q1*57.2957795;
        }

        // angle_theta = sqrt(pow(angle_theta, 2));
        // angle_beta = sqrt(pow(angle_beta, 2));

        hwlib::cout << "beta(q2): " << angle_beta << " theta(q1): " << angle_theta << "\n";     
    }


        uint16_t calculate_inverse_kinematics_c::get_angle_theta() {
            return angle_theta;
        }

        uint16_t calculate_inverse_kinematics_c::get_angle_beta() {
            return angle_beta;
        }

}//end name space r2d2::robot_arm