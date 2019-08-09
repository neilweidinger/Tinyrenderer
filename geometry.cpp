#include <cmath>
#include "geometry.hpp"

namespace geometry {

// ---------- VECTOR CLASS ----------

Vector::Vector(float x, float y, float z)
  : x_val_ {x},
    y_val_ {y},
    z_val_ {z}
{}

float Vector::getX() const {
    return x_val_;
}

float Vector::getY() const {
    return y_val_;
}

float Vector::getZ() const {
    return z_val_;
}

int Vector::dotProduct(const Vector& Vec) const {
    return this->x_val_ * Vec.x_val_ +
           this->y_val_ * Vec.y_val_ +
           this->z_val_ * Vec.z_val_;
}

// destructively scalar multiples a vector
void Vector::scalarMultiply(int scalar) {
    x_val_ *= scalar;
    y_val_ *= scalar;
    z_val_ *= scalar;
}

// non-destructively scalar multiplies a vector, returning a new copy
Vector scalarMultiply(int scalar, Vector vec) {
    return Vector {vec.x_val_ * scalar, vec.y_val_ * scalar, vec.z_val_ * scalar};
}

Vector& Vector::operator+=(const Vector& rhs) {
    x_val_ += rhs.x_val_;
    y_val_ += rhs.y_val_;
    z_val_ += rhs.z_val_;

    return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
    x_val_ -= rhs.x_val_;
    y_val_ -= rhs.y_val_;
    z_val_ -= rhs.z_val_;

    return *this;
}

float length(const Vector& vec) {
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
    return os << vec.x_val_ << vec.y_val_ << vec.z_val_;
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

    Vector projection_onto_ray = scalarMultiply((center_.dotProduct(ray) / ray.dotProduct(ray)), ray);
    Vector center_to_projection = center_ - projection_onto_ray;
    float center_to_projection_dist = length(center_to_projection);

    return radius_ > center_to_projection_dist;
}

}  // namespace geometry
