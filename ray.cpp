#include "ray.hpp"

namespace geometry {

Ray::Ray(const geometry::Vector& origin, const geometry::Vector& direction)
  : origin_ {origin},
    dir_ {direction}
{}

}  // namespace geometry
