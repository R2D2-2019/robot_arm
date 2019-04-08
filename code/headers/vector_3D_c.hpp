#pragma once

/**
 * Class point_3d is used for xyz 3D coordinates
 */

namespace r2d2::robot_arm {
    template <class Type>
    class vector_3D_c {
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
         * @param vector_3D_c rhs
         * @return bool
         **/
        bool operator==(const vector_3D_c<Type> &rhs) const {
            return x == rhs.x && y == rhs.y && z == rhs.z;
        }

        /**
        * vector_3D_c
         default constructor.
        **/
        vector_3D_c() : x(), y(), z() {
        }

        /**
         * vector_3D_c constructor.
         * Initializes x, y, z in respectively.
         *
         * @param x
         * @param y
         * @param z
         **/
        vector_3D_c(const Type &x, const Type &y, const Type &z)
            : x(x), y(y), z(z) {
        }

        /**
         * vector_3D_c constructor.
         * Initializes x, y, z in with all_values.
         *
         * @param int all_values
         **/
        vector_3D_c(const Type &all_values)
            : vector_3D_c(all_values, all_values, all_values) {
        }

        /**
         * vector_3D_c default destructor.
         **/
        ~vector_3D_c() = default;

        /**
         * vector_3D_c operator+.
         * Sums a point3_d with another vector_3D_c, returns the result
         *
         * @param vector_3D_c rhs
         * @return vector_3D_c
        
        **/
        vector_3D_c<Type> operator+(const vector_3D_c<Type> &rhs) const {
            return vector_3D_c<Type>(x + rhs.x, y + rhs.y, z + rhs.z);
        }

        /**
         * vector_3D_c operator+.
         * Increases all values from vector_3D_c (x, y, z) with the int
         *parameter rhs
         *
         * @param int rhs
         * @return vector_3D_c
         **/
        vector_3D_c<Type> operator+(const Type &rhs) const {
            return *this + vector_3D_c<Type>(rhs);
        }

        /**
         * vector_3D_c operator +=
         * increases all values with rhs
         *
         * @param vector_3D_c rhs
         * @return vector_3D_c&
         *
         **/
        vector_3D_c<Type> &operator+=(const vector_3D_c<Type> &rhs) {
            *this = *this + rhs;
            return *this;
        }

        /** vector_3D_c operator +=
         * increases all values with rhs
         *
         * @param int rhs
         * @return vector_3D_c&
         **/
        vector_3D_c<Type> &operator+=(const Type &rhs) {
            return *this += vector_3D_c(rhs);
        }

        /**
         * vector_3D_c operator++.
         * Increases all values from vector_3D_c (x, y, z) with 1
         *
         * @return vector_3D_c&
         **/
        vector_3D_c<Type> &operator++(int) {
            return *this += 1;
        }

        /**
         * vector_3D_c operator-
         * Decreases all values from point_3d (x, y, z) with rhs
         *
         * @param vector_3D_c
         * @return vector_3D_c
         **/
        vector_3D_c<Type> operator-(const vector_3D_c<Type> &rhs) const {
            return vector_3D_c<Type>(x - rhs.x, y - rhs.y, z - rhs.z);
        }

        /**
         * vector_3D_c operator-.
         * Decreases all values from vector_3D_c (x, y, z) with the int
         *parameter rhs
         *
         * @param int rhs
         * @return vector_3D_c
         **/
        vector_3D_c<Type> operator-(const Type &rhs) const {
            return *this - vector_3D_c<Type>(rhs);
        }

        /**
         * vector_3D_c operator -=
         * Decreases all values with vector_3D_c rhs
         *
         * @param vector_3D_c rhs
         * @return vector_3D_c&
         **/
        vector_3D_c<Type> &operator-=(const vector_3D_c<Type> &rhs) {
            *this = *this - rhs;
            return *this;
        }

        /**
         * vector_3D_c operator -=
         * Decreases all values with int rhs
         *
         * @param vector_3D_c rhs
         * @return vector_3D_c&
         **/
        vector_3D_c<Type> &operator-=(const Type &rhs) {
            return *this -= vector_3D_c<Type>(rhs);
        }

        /**
         * vector_3D_c operator--.
         * Decreases all values from vector_3D_c (x, y, z) with 1
         *
         * @return vector_3D_c&
         **/
        vector_3D_c<Type> &operator--(int) {
            return *this -= 1;
        }

        /**
         * vector_3D_c operator/
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param vector_3D_c rhs
         * @return vector_3D_c
         **/
        vector_3D_c<Type> operator/(const vector_3D_c<Type> &rhs) const {
            return vector_3D_c<Type>((x / rhs.x), (y / rhs.y), (z / rhs.z));
        }

        /**
         * vector_3D_c operator/
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param int rhs
         * @return vector_3D_c
         **/
        vector_3D_c<Type> operator/(const Type &rhs) const {
            return *this / vector_3D_c<Type>(rhs);
        }

        /**
         * vector_3D_c operator/=
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param coordinate3D_c rhs
         * @return vector_3D_c&
         **/
        vector_3D_c<Type> &operator/=(const vector_3D_c<Type> &rhs) {
            *this = *this / rhs;
            return *this;
        }

        /**
         * vector_3D_c operator/=
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param int rhs
         * @return vector_3D_c&
         **/
        vector_3D_c<Type> &operator/=(const Type &rhs) {
            return *this /= vector_3D_c<Type>(rhs);
        }
    };
} // namespace r2d2::robot_arm