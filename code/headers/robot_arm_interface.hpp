#pragma once

#include "vector3.hpp"
#include <hwlib.hpp>
#include <base_module.hpp>

/**
 * Class robot_arm_interface provides the interface for different robot arms.
 */
namespace r2d2::robot_arm {
    class robot_arm_interface_c: public base_module_c {

    public:

        robot_arm_interface_c(base_comm_c &comm) : base_module_c(comm){

            comm.listen_for_frames({r2d2::frame_type::ROBOT_ARM});
        }

        void process()override{
            comm.request(r2d2::frame_type::ROBOT_ARM);
            while (comm.has_data()){
                auto frame = comm.get_data();
                const auto data = frame.as_frame_type<frame_type::ROBOT_ARM>();
                move_head_to_coordinate(vector3i_c(data.x, data.y, data.z), data.speed);

            }
        }
        /**
         * This function moves the robot arm head to a certain 3d location
         * at a given speed.
         *
         * @param coordinate
         * @param speed
         */
        virtual void move_head_to_coordinate(const vector3i_c &coordinate,
                                             const uint16_t &speed) = 0;

        /**
         * This function moves the robot arm head to a certain 3d location.
         *
         * @param coordinate
         */
        virtual void move_head_to_coordinate(const vector3i_c &coordinate) = 0;
    };
}; // namespace r2d2::robot_arm