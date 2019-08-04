#include <cmath>
#include "geometry.hpp"

namespace geometry {

// ---------- VECTOR CLASS ----------

Vector::Vector(uint8_t r, uint8_t g, uint8_t b)
  : r_val_ {r},
    g_val_ {g},
    b_val_ {b}
{}

int Vector::dotProduct(const Vector& Vec) const {
    return this->r_val_ * Vec.r_val_ +
           this->g_val_ * Vec.g_val_ +
           this->b_val_ * Vec.b_val_;
}

// destructively scalar multiples a vector
void Vector::scalarMultiply(int scalar) {
    r_val_ *= scalar;
    g_val_ *= scalar;
    b_val_ *= scalar;
}

// non-destructively scalar multiplies a vector, returning a new copy
Vector Vector::scalarMultiply(int scalar) const {
    return Vector(r_val_ * scalar, g_val_ * scalar, b_val_ * scalar);
}

Vector& Vector::operator+=(const Vector& rhs) {
    r_val_ += rhs.r_val_;
    g_val_ += rhs.g_val_;
    b_val_ += rhs.b_val_;

    return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
    r_val_ -= rhs.r_val_;
    g_val_ -= rhs.g_val_;
    b_val_ -= rhs.b_val_;

    return *this;
}

double length(const Vector& vec) {
    return std::sqrt(vec.dotProduct(vec));
}

Vector operator+(Vector lhs, const Vector& rhs) {
    lhs += rhs;

    return lhs;
}

Vector operator-(Vector lhs, const Vector& rhs) {
    lhs -= rhs;

    return lhs;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    return os << vec.r_val_ << vec.g_val_ << vec.b_val_;
}

// ---------- SPHERE CLASS ----------

Sphere::Sphere(Vector center, int radius)
  : center_ {center},
    radius_ {radius} {}

bool Sphere::intersectsWithRay(const Vector& ray) {
    // sphere is behind ray
    if (center_.dotProduct(ray) < 0) {
        return false;
    }

    Vector projection_onto_ray = ray.scalarMultiply((center_.dotProduct(ray) / ray.dotProduct(ray)));
    Vector center_to_projection = center_ - projection_onto_ray;
    double center_to_projection_dist = length(center_to_projection);

    return center_to_projection_dist > radius_;
}

}  // namespace geometry
