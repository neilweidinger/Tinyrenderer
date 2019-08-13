#include <cmath>

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

    if (discriminant == 0) {
        float root = -b / 2 * a;

        return root >= 0;
    }

    float root1 = (-b + std::sqrt(discriminant)) / 2 * a;
    float root2 = (-b - std::sqrt(discriminant)) / 2 * a;

    return root1 >= 0 || root2 >= 0;
}

}  // namespace geometry
