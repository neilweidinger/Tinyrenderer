#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "vector.hpp"
#include "ray.hpp"

namespace geometry {

class Sphere {
    public:
        Sphere(Vector center, int radius);
        float findIntersection(const Ray& ray) const;
        Vector getCenter() const;

    private:
        Vector center_;
        int radius_;
};

}  // namespace geometry

#endif  // SPHERE_HPP
