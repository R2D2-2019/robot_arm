#include <gcode_generator.hpp>

namespace r2d2::robot_arm {
    template <size_t Size>
    class uarm_gcode_generator_c : public gcode_generator_c<Size> {
    public:

        /**
         * Converts a vector3i_c to a gcode command for uArm
         *
         * @param vector3i
         * @param uint8_t speed
         * */
        void coordinate_to_gcode(const vector3i_c &coordinate, const uint16_t &speed) {
            char x_string[11]; // max number of int digits (10) + '\0' = 11
            char y_string[11];
            char z_string[11];
            char speed_string[11];
            this->int_to_string(coordinate.x, x_string);
            this->int_to_string(coordinate.y, y_string);
            this->int_to_string(coordinate.z, z_string);
            this->int_to_string(speed, speed_string);
            this->append("#1 G0 X");
            this->append(x_string);
            this->append(" Y");
            this->append(y_string);
            this->append(" Z");
            this->append(z_string);
            this->append(" F");
            this->append(speed_string);
            this->append("\n");
        }

        void polar_coordinate_to_gcode(const vector3i_c &coordinate, const uint16_t &speed){
            char s_string[11]; // max number of int digits (10) + '\0' = 11
            char r_string[11];
            char h_string[11];
            char speed_string[11];
            this->int_to_string(coordinate.x, s_string);
            this->int_to_string(coordinate.y, r_string);
            this->int_to_string(coordinate.z, h_string);
            this->int_to_string(speed, speed_string);
            this->append("#2 G2201 S");
            this->append(s_string);
            this->append(" R");
            this->append(r_string);
            this->append(" H");
            this->append(h_string);
            this->append(" F");
            this->append(speed_string);
            this->append("\n");
        }

        void rotate_id_motor_degree_to_gcode(const uint8_t &id, const uint16_t &degree){
            char id_string[2];
            char degree_string[4];
            this->int_to_string(id, id_string);
            this->int_to_string(degree, degree_string);
            this->append("#3 G2202 N");
            this->append(id_string);
            this->append(" V");
            this->append(degree_string);
            this->append("\n");
        }

        void relative_displacement_to_gcode(const vector3i_c &coordinate, const uint16_t &speed) {
            char x_string[11]; // max number of int digits (10) + '\0' = 11
            char y_string[11];
            char z_string[11];
            char speed_string[11];
            this->int_to_string(coordinate.x, x_string);
            this->int_to_string(coordinate.y, y_string);
            this->int_to_string(coordinate.z, z_string);
            this->int_to_string(speed, speed_string);
            this->append("#4 G2204 X");
            this->append(x_string);
            this->append(" Y");
            this->append(y_string);
            this->append(" Z");
            this->append(z_string);
            this->append(" F");
            this->append(speed_string);
            this->append("\n");
        }

        void relative_displacement_polar_to_gcode(const vector3i_c &coordinate, const uint16_t &speed){
            char s_string[11]; // max number of int digits (10) + '\0' = 11
            char r_string[11];
            char h_string[11];
            char speed_string[11];
            this->int_to_string(coordinate.x, s_string);
            this->int_to_string(coordinate.y, r_string);
            this->int_to_string(coordinate.z, h_string);
            this->int_to_string(speed, speed_string);
            this->append("#5 G2205 S");
            this->append(s_string);
            this->append(" R");
            this->append(r_string);
            this->append(" H");
            this->append(h_string);
            this->append(" F");
            this->append(speed_string);
            this->append("\n");
        }

        void attach_all_joint_motors_to_gcode(){
            this->append("#6 M17\n");
        }

        void detach_all_joint_motors_to_gcode(){
            this->append("#7 M2019\n");
        }

        void return_cartesian_coordinates_by_speed(const uint16_t &speed){
            char speed_string[11];
            this->int_to_string(speed, speed_string);
            this->append("#8 M2120 V");
            this->append(speed_string);
            this->append("\n");
        }

        void attach_motor_by_id_to_gcode(const uint8_t &id){
            char id_string[2];
            this->int_to_string(id, id_string);
            this->append("#9 M2201 N");
            this->append(id_string);
            this->append("\n");
        }

        void init(const uint8_t &on_off){
            char on_off_string[2];
            this->int_to_string(on_off, on_off_string);
            this->append("#1 M2122 V");
            this->append(on_off_string);
            this->append("\n");
        }
    };
} // namespace r2d2::robot_arm