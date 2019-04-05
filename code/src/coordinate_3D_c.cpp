#include "coordinate_3D_c.hpp"

namespace r2d2::robot_arm {
    bool coordinate_3D_c::operator==(const coordinate_3D_c &rhs) const {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    coordinate_3D_c::coordinate_3D_c():
        coordinate_3D_c(0, 0, 0)
    {}

    coordinate_3D_c::coordinate_3D_c(const int &x, const int &y, const int &z):
        x(x), y(y), z(z)
    {}

    coordinate_3D_c::coordinate_3D_c(const int &all_values):
        coordinate_3D_c(all_values, all_values, all_values)
    {}

    coordinate_3D_c coordinate_3D_c::operator+(const coordinate_3D_c &rhs) const {
        return coordinate_3D_c(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    coordinate_3D_c coordinate_3D_c::operator+(const int &rhs) const {
        return *this + coordinate_3D_c(rhs);
    }

    coordinate_3D_c& coordinate_3D_c::operator+=(const coordinate_3D_c &rhs) {
        *this = *this + rhs;
        return *this;
    }

    coordinate_3D_c& coordinate_3D_c::operator+=(const int &rhs) {
        return *this += coordinate_3D_c(rhs);
    }

    coordinate_3D_c& coordinate_3D_c::operator++(int) {
        return *this += 1;
    }

    coordinate_3D_c coordinate_3D_c::operator-(const coordinate_3D_c &rhs) const {
        return coordinate_3D_c(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    coordinate_3D_c coordinate_3D_c::operator-(const int &rhs) const {
        return *this - coordinate_3D_c(rhs);
    }

    coordinate_3D_c& coordinate_3D_c::operator-=(const coordinate_3D_c &rhs) {
        *this = *this - rhs;
        return *this;
    }

    coordinate_3D_c& coordinate_3D_c::operator-=(const int &rhs) {
        return *this -= coordinate_3D_c(rhs);
    }

    coordinate_3D_c& coordinate_3D_c::operator--(int) {
        return *this -= 1;
    }

    coordinate_3D_c coordinate_3D_c::operator/(const coordinate_3D_c &rhs) const {
        return coordinate_3D_c(static_cast<int>(x / rhs.x), 
            static_cast<int>(y / rhs.y),
            static_cast<int>(z / rhs.z));
    }

    coordinate_3D_c coordinate_3D_c::operator/(const int &rhs) const {
        return *this / coordinate_3D_c(rhs);
    }

    coordinate_3D_c& coordinate_3D_c::operator/=(const coordinate_3D_c &rhs) {
        *this = *this / rhs;
        return *this;
    }

    coordinate_3D_c& coordinate_3D_c::operator/=(const int &rhs) {
        return *this /= coordinate_3D_c(rhs);
    }
}

