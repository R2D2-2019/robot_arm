#pragma once

/**
 * Class point_3d is used for xyz 3D coordinates
 */

namespace r2d2::robot_arm {
    template <class Type>
    class vector3_c {
    public:
        /**
         * 3 public member variables x y z.
         * Public member variables x y z.
         *
         * @param x
         * @param y
         * @param z
         **/
        Type x;
        Type y;
        Type z;

        /**
         * Operator == for equality checking.
         * Required for catch2.
         *
         * @param vector3_c rhs
         * @return bool
         **/
        bool operator==(const vector3_c<Type> &rhs) const {
            return x == rhs.x && y == rhs.y && z == rhs.z;
        }

        /**
        * vector3_c
         default constructor.
        **/
        vector3_c() : x(), y(), z() {
        }

        /**
         * vector3_c constructor.
         * Initializes x, y, z in respectively.
         *
         * @param x
         * @param y
         * @param z
         **/
        vector3_c(const Type &x, const Type &y, const Type &z)
            : x(x), y(y), z(z) {
        }

        /**
         * vector3_c constructor.
         * Initializes x, y, z in with all_values.
         *
         * @param int all_values
         **/
        vector3_c(const Type &all_values)
            : vector3_c(all_values, all_values, all_values) {
        }

        /**
         * vector3_c default destructor.
         **/
        ~vector3_c() = default;

        /**
         * vector3_c operator+.
         * Sums a point3_d with another vector3_c, returns the result
         *
         * @param vector3_c rhs
         * @return vector3_c
        
        **/
        vector3_c<Type> operator+(const vector3_c<Type> &rhs) const {
            return vector3_c<Type>(x + rhs.x, y + rhs.y, z + rhs.z);
        }

        /**
         * vector3_c operator+.
         * Increases all values from vector3_c (x, y, z) with the int
         *parameter rhs
         *
         * @param int rhs
         * @return vector3_c
         **/
        vector3_c<Type> operator+(const Type &rhs) const {
            return *this + vector3_c<Type>(rhs);
        }

        /**
         * vector3_c operator +=
         * increases all values with rhs
         *
         * @param vector3_c rhs
         * @return vector3_c&
         *
         **/
        vector3_c<Type> &operator+=(const vector3_c<Type> &rhs) {
            *this = *this + rhs;
            return *this;
        }

        /** vector3_c operator +=
         * increases all values with rhs
         *
         * @param int rhs
         * @return vector3_c&
         **/
        vector3_c<Type> &operator+=(const Type &rhs) {
            return *this += vector3_c(rhs);
        }

        /**
         * vector3_c operator++.
         * Increases all values from vector3_c (x, y, z) with 1
         *
         * @return vector3_c&
         **/
        vector3_c<Type> &operator++(int) {
            return *this += 1;
        }

        /**
         * vector3_c operator-
         * Decreases all values from point_3d (x, y, z) with rhs
         *
         * @param vector3_c
         * @return vector3_c
         **/
        vector3_c<Type> operator-(const vector3_c<Type> &rhs) const {
            return vector3_c<Type>(x - rhs.x, y - rhs.y, z - rhs.z);
        }

        /**
         * vector3_c operator-.
         * Decreases all values from vector3_c (x, y, z) with the int
         *parameter rhs
         *
         * @param int rhs
         * @return vector3_c
         **/
        vector3_c<Type> operator-(const Type &rhs) const {
            return *this - vector3_c<Type>(rhs);
        }

        /**
         * vector3_c operator -=
         * Decreases all values with vector3_c rhs
         *
         * @param vector3_c rhs
         * @return vector3_c&
         **/
        vector3_c<Type> &operator-=(const vector3_c<Type> &rhs) {
            *this = *this - rhs;
            return *this;
        }

        /**
         * vector3_c operator -=
         * Decreases all values with int rhs
         *
         * @param vector3_c rhs
         * @return vector3_c&
         **/
        vector3_c<Type> &operator-=(const Type &rhs) {
            return *this -= vector3_c<Type>(rhs);
        }

        /**
         * vector3_c operator--.
         * Decreases all values from vector3_c (x, y, z) with 1
         *
         * @return vector3_c&
         **/
        vector3_c<Type> &operator--(int) {
            return *this -= 1;
        }

        /**
         * vector3_c operator/
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param vector3_c rhs
         * @return vector3_c
         **/
        vector3_c<Type> operator/(const vector3_c<Type> &rhs) const {
            return vector3_c<Type>((x / rhs.x), (y / rhs.y), (z / rhs.z));
        }

        /**
         * vector3_c operator/
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param int rhs
         * @return vector3_c
         **/
        vector3_c<Type> operator/(const Type &rhs) const {
            return *this / vector3_c<Type>(rhs);
        }

        /**
         * vector3_c operator/=
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param coordinate3D_c rhs
         * @return vector3_c&
         **/
        vector3_c<Type> &operator/=(const vector3_c<Type> &rhs) {
            *this = *this / rhs;
            return *this;
        }

        /**
         * vector3_c operator/=
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param int rhs
         * @return vector3_c&
         **/
        vector3_c<Type> &operator/=(const Type &rhs) {
            return *this /= vector3_c<Type>(rhs);
        }
    };

    typedef vector3_c<int> vector3i_c;
} // namespace r2d2::robot_arm