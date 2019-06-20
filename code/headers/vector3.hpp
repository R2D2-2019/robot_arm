#pragma once

/**
 * @brief
 * Class point_3d is used for xyz 3D coordinates 
 * 
 * @tparam Type The type of the vector_c x, y and z
 */

namespace r2d2::robot_arm {
    template <class Type>
    class vector3_c {
    public:
        /**
         * @brief
         * 3 public member variables x y z.
         * Public member variables x y z.
         *
         * @param x The x Type parameter
         * @param y The y Type parameter
         * @param z The z Type parameter
         */
        Type x;
        Type y;
        Type z;

        /**
         * @brief
         * Operator == for equality checking.
         * Required for catch2.
         *
         * @param rhs Vector3_c<Type> that needs to be compared
         * @return true if equal false if not equal
         */
        bool operator==(const vector3_c<Type> &rhs) const {
            return x == rhs.x && y == rhs.y && z == rhs.z;
        }

        /**
         * @brief
         * vector3_c
         * default constructor.
         */
        vector3_c() : x(), y(), z() {
        }

        /**
         * @brief
         * vector3_c constructor.
         * Initializes x, y & z respectively.
         *
         * @param x
         * @param y
         * @param z
         */
        vector3_c(const Type &x, const Type &y, const Type &z)
            : x(x), y(y), z(z) {
        }

        /**
         * @brief
         * vector3_c constructor.
         * Initializes x, y & z in with all_values.
         *
         * @param all_values
         */
        vector3_c(const Type &all_values)
            : vector3_c(all_values, all_values, all_values) {
        }

        /**
         * @brief
         * vector3_c operator+.
         * Sums a point3_d with another vector3_c, returns the result
         *
         * @param rhs vector3_c<Type>
         * @return vector3_c<Type>
         */
        vector3_c<Type> operator+(const vector3_c<Type> &rhs) const {
            return vector3_c<Type>(x + rhs.x, y + rhs.y, z + rhs.z);
        }

        /**
         * @brief
         * vector3_c operator+.
         * Increases all values from vector3_c (x, y, z) with the Type
         * parameter rhs
         *
         * @param rhs
         * @return vector3_c
         */
        vector3_c<Type> operator+(const Type &rhs) const {
            return *this + vector3_c<Type>(rhs);
        }

        /**
         * @brief
         * vector3_c operator +=
         * increases all values with rhs
         *
         * @param rhs The value that needs to be added as vector3_c<Type>
         * @return Returns vector3_c&
         *
         */
        vector3_c<Type> &operator+=(const vector3_c<Type> &rhs) {
            *this = *this + rhs;
            return *this;
        }

        /** 
         * @brief
         * vector3_c operator +=
         * increases all values with rhs
         *
         * @param rhs The value that needs to be added as Type
         * @return vector3_c&
         */
        vector3_c<Type> &operator+=(const Type &rhs) {
            return *this += vector3_c(rhs);
        }

        /**
         * @brief
         * vector3_c operator++.
         * Increases all values from vector3_c (x, y, z) with 1
         *
         * @return vector3_c&
         */
        vector3_c<Type> &operator++(int) {
            return *this += 1;
        }

        /**
         * @brief
         * vector3_c operator-
         * Decreases all values from point_3d (x, y, z) with rhs
         *
         * @param rhs Value that needs to be subtracted
         * @return vector3_c
         */
        vector3_c<Type> operator-(const vector3_c<Type> &rhs) const {
            return vector3_c<Type>(x - rhs.x, y - rhs.y, z - rhs.z);
        }

        /**
         * @brief
         * vector3_c operator-.
         * Decreases all values from vector3_c (x, y, z) with the Type value
         * parameter rhs
         *
         * @param rhs the value that needs to be subtracted
         * @return vector3_c
         */
        vector3_c<Type> operator-(const Type &rhs) const {
            return *this - vector3_c<Type>(rhs);
        }

        /**
         * @brief
         * vector3_c operator -=
         * Decreases all values with vector3_c rhs
         *
         * @param rhs The value that needs to be subtracted
         * @return vector3_c&
         */
        vector3_c<Type> &operator-=(const vector3_c<Type> &rhs) {
            *this = *this - rhs;
            return *this;
        }

        /**
         * @brief
         * vector3_c operator -=
         * Decreases all values with Type rhs
         *
         * @param rhs The value that needs to be subtracted
         * @return vector3_c&
         */
        vector3_c<Type> &operator-=(const Type &rhs) {
            return *this -= vector3_c<Type>(rhs);
        }

        /**
         * @brief
         * vector3_c operator--.
         * Decreases all values from vector3_c (x, y, z) with 1
         *
         * @return vector3_c&
         */
        vector3_c<Type> &operator--(int) {
            return *this -= 1;
        }

        /**
         * @brief
         * vector3_c operator*
         * Multiplies x, y, z with rhs.x, y, z
         *
         * @param rhs vector3_c<Type> the value that is multiplied with
         * @return vector3c<Type>
         */
        vector3_c<Type> operator*(const vector3_c &rhs) const {
            return vector3_c<Type>(x * rhs.x, y * rhs.y, z * rhs.z);
        }

        /**
         * @brief
         * vector3_c operator*
         *
         * Multiplies x y z with rhs
         * @param rhs the value that is multiplied with
         * @return vector3_c<Type>
         */
        vector3_c<Type> operator*(const Type &rhs) const {
            return *this * vector3_c<Type>(rhs);
        }

        /**
         * @brief
         * vector3_c operator*=
         * Multiplies xyz with rhs
         *
         * @param rhs the value that is multiplied with
         * @return vector3_c<Type>&
         */
        vector3_c<Type> &operator*=(const vector3_c<Type> &rhs) {
            *this = *this * rhs;
            return *this;
        }
        /**
         * @brief
         * vector3_c operator*=
         * Multiplies xyz with rhs
         *
         * @param rhs the value that is multiplied with
         * @return vector3_c<Type>&
         */
        vector3_c<Type> &operator*=(const Type &rhs) {
            return *this *= vector3_c<Type>(rhs);
        }

        /**
         * @brief
         * vector3_c operator/
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param rhs The value of the divider
         * @return vector3_c
         */
        vector3_c<Type> operator/(const vector3_c<Type> &rhs) const {
            return vector3_c<Type>((x / rhs.x), (y / rhs.y), (z / rhs.z));
        }

        /**
         * @brief
         * vector3_c operator/
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param rhs The value of the divider
         * @return vector3_c
         */
        vector3_c<Type> operator/(const Type &rhs) const {
            return *this / vector3_c<Type>(rhs);
        }

        /**
         * @brief
         * vector3_c operator/=
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param rhs The value of the divider
         * @return vector3_c&
         */
        vector3_c<Type> &operator/=(const vector3_c<Type> &rhs) {
            *this = *this / rhs;
            return *this;
        }

        /**
         * @brief
         * vector3_c operator/=
         * Devides all values with rhs.
         * Note that this class contains of ints only
         *
         * @param rhs The value of the divider
         * @return vector3_c&
         */
        vector3_c<Type> &operator/=(const Type &rhs) {
            return *this /= vector3_c<Type>(rhs);
        }
    };

    typedef vector3_c<int> vector3i_c;
} // namespace r2d2::robot_arm