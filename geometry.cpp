#include "geometry.hpp"

namespace geometry {

Vector::Vector()
  : r_val_ {0},
    g_val_ {0},
    b_val_ {0}
{}

Vector::Vector(uint8_t r, uint8_t g, uint8_t b)
  : r_val_ {r},
    g_val_ {g},
    b_val_ {b}
{}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    return os << vec.r_val_ << vec.g_val_ << vec.b_val_;
}

}  // namespace geometry
