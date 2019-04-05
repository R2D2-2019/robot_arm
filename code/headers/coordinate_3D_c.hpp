#pragma once

/**
 * Class point_3d is used for xyz 3D coordinates
 */

namespace r2d2::robot_arm {
    class coordinate_3D_c {
    public:
        /**
         * Operator == for equality checking.
         * Required for catch2.
         *
         * @param coordinate_3D_c rhs
         * @return bool
         **/
        bool operator==(const coordinate_3D_c &rhs) const;
        /**
         * 3 public member variables x y z.
         * Public member variables x y z correlate to real world millimeters.
         *
         * @param x
         * @param y
         * @param z
         **/
        int x, y, z;

        /**
        * coordinate_3D_c
         default constructor.
        * Initializes x, y, z with 0.
        **/
        coordinate_3D_c();

        /**
         * coordinate_3D_c constructor.
         * Initializes x, y, z in respectively.
         *
         * @param x
         * @param y
         * @param z
         **/
        coordinate_3D_c(const int &x, const int &y, const int &z);
        /**
         * coordinate_3D_c constructor.
         * Initializes x, y, z in with all_values.
         *
         * @param int all_values
         **/
        coordinate_3D_c(const int &all_values);

        /**
         * coordinate_3D_c default destructor.
         **/
        ~coordinate_3D_c() = default;

        /**
         * coordinate_3D_c operator+.
         * Sums a point3_d with another coordinate_3D_c, returns the result
         *
         * @param coordinate_3D_c rhs
         * @return coordinate_3D_c
        
        **/
        coordinate_3D_c operator+(const coordinate_3D_c &rhs) const;

        /**
         * coordinate_3D_c operator+.
         * Increases all values from coordinate_3D_c (x, y, z) with the int
         *parameter rhs
         *
         * @param int rhs
         * @return coordinate_3D_c
         **/
        coordinate_3D_c operator+(const int &rhs) const;

        /**
         * coordinate_3D_c operator +=
         * increases all values with rhs
         *
         * @param coordinate_3D_c rhs
         * @return coordinate_3D_c&
         *
         **/
        coordinate_3D_c &operator+=(const coordinate_3D_c &rhs);

        /** coordinate_3D_c operator +=
         * increases all values with rhs
         *
         * @param int rhs
         * @return coordinate_3D_c&
         **/
        coordinate_3D_c &operator+=(const int &rhs);

        /**
         * coordinate_3D_c operator++.
         * Increases all values from coordinate_3D_c (x, y, z) with 1
         *
         * @return coordinate_3D_c&
         **/
        coordinate_3D_c &operator++(int);

        /**
         * coordinate_3D_c operator-
         * Decreases all values from point_3d (x, y, z) with rhs
         *
         * @param coordinate_3D_c
         * @return coordinate_3D_c
         **/
        coordinate_3D_c operator-(const coordinate_3D_c &rhs) const;

        /**
         * coordinate_3D_c operator-.
         * Decreases all values from coordinate_3D_c (x, y, z) with the int
         *parameter rhs
         *
         * @param int rhs
         * @return coordinate_3D_c
         **/
        coordinate_3D_c operator-(const int &rhs) const;

        /**
         * coordinate_3D_c operator -=
         * Decreases all values with coordinate_3D_c rhs
         *
         * @param coordinate_3D_c rhs
         * @return coordinate_3D_c&
         **/
        coordinate_3D_c &operator-=(const coordinate_3D_c &rhs);

        /**
         * coordinate_3D_c operator -=
         * Decreases all values with int rhs
         *
         * @param coordinate_3D_c rhs
         * @return coordinate_3D_c&
         **/
        coordinate_3D_c &operator-=(const int &rhs);

        /**
         * coordinate_3D_c operator--.
         * Decreases all values from coordinate_3D_c (x, y, z) with 1
         *
         * @return coordinate_3D_c&
         **/
        coordinate_3D_c &operator--(int);

        /**
         * coordinate_3D_c operator/
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param coordinate_3D_c rhs
         * @return coordinate_3D_c
         **/
        coordinate_3D_c operator/(const coordinate_3D_c &rhs) const;

        /**
         * coordinate_3D_c operator/
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param int rhs
         * @return coordinate_3D_c
         **/
        coordinate_3D_c operator/(const int &rhs) const;

        /**
         * coordinate_3D_c operator/=
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param coordinate3D_c rhs
         * @return coordinate_3D_c&
         **/
        coordinate_3D_c &operator/=(const coordinate_3D_c &rhs);

        /**
         * coordinate_3D_c operator/=
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param int rhs
         * @return coordinate_3D_c&
         **/
        coordinate_3D_c &operator/=(const int &rhs);
    };
} // namespace r2d2::robot_arm