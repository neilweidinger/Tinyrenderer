#include "ray.hpp"

namespace geometry {

Ray::Ray(const geometry::Vector& origin, const geometry::Vector& direction)
  : origin_ {origin},
    dir_ {normalize(direction)}
{}

geometry::Vector Ray::getOrigin() const {
    return origin_;
}

geometry::Vector Ray::getDir() const {
    return dir_;
}

}  // namespace geometry
