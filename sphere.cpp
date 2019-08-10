#include "sphere.hpp"

namespace geometry {

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
