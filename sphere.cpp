#include "sphere.hpp"

namespace geometry {

Sphere::Sphere(Vector center, int radius)
  : center_ {center},
    radius_ {radius} {}

bool Sphere::intersectsWithRay(const Ray& ray) {
    geometry::Vector oc = ray.getOrigin() - center_;
    float a = 1;
    float b = 2 * ray.getDir().dotProduct(ray.getOrigin() - center_);
    float c = oc.dotProduct(oc) - radius_ * radius_;

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }

    return true;
}

}  // namespace geometry
