#include "geometry.hpp"

namespace geometry {

// ---------- VECTOR CLASS ----------

Vector::Vector(uint8_t r, uint8_t g, uint8_t b)
  : r_val_ {r},
    g_val_ {g},
    b_val_ {b}
{}

int Vector::dotProduct(Vector Vec) {
    return this->r_val_ * Vec.r_val_ +
           this->g_val_ * Vec.g_val_ +
           this->b_val_ * Vec.b_val_;
}

Vector Vector::scalarMultiply(int scalar) {
    r_val_ *= scalar;
    g_val_ *= scalar;
    b_val_ *= scalar;

    return *this;
}

std::ostream& operator<<(std::ostream& os, Vector vec) {
    return os << vec.r_val_ << vec.g_val_ << vec.b_val_;
}

// ---------- SPHERE CLASS ----------

Sphere::Sphere(Vector center, int radius)
  : center_ {center},
    radius_ {radius} {}

bool Sphere::intersectsWithRay(Vector ray) {
    // sphere is behind ray
    if (center_.dotProduct(ray) < 0) {
        return false;
    }

    Vector projection_onto_ray = ray.scalarMultiply((center_.dotProduct(ray) / ray.dotProduct(ray)));


}

}  // namespace geometry
