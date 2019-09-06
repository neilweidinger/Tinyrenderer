#include "ray.hpp"

namespace geometry {

Ray::Ray(const Vector& origin, const Vector& direction)
  : origin_ {origin},
    dir_ {normalize(direction)}
{}

Vector Ray::getOrigin() const {
    return origin_;
}

Vector Ray::getDirection() const {
    return dir_;
}

Vector Ray::pointAtParameter(float t) const {
    return origin_ + scalarMultiply(t, dir_);
}

}  // namespace geometry
