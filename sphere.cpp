#include <cmath>
#include "sphere.hpp"

namespace geometry {

Sphere::Sphere(Vector center, int radius)
  : center_ {center},
    radius_ {radius} {}

// returns t where t represents distance along direction vector from ray origin
// returns -1.0 if there is no t (ray doesn't hit sphere, negative value so equivalent to ray intersecting behind camera)
// returns smaller t if there are two (first t that ray hits)
float Sphere::findIntersection(const Ray& ray) const {
    geometry::Vector oc = ray.getOrigin() - center_;
    float a = 1;
    float b = 2 * ray.getDir().dotProduct(ray.getOrigin() - center_);
    float c = oc.dotProduct(oc) - radius_ * radius_;

    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        // t value doesn't actually exist, but return a negative value so that
        // this is equivalent to the ray intersecting behind the camera
        return -1.0;
    }

    return (-b - std::sqrt(discriminant)) / 2 * a;
}

Vector Sphere::getCenter() const {
    return center_;
}

}  // namespace geometry
