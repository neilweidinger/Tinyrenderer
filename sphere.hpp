#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "vector.hpp"
#include "ray.hpp"

namespace geometry {

class Sphere {
    public:
        Sphere(Vector center, int radius);
        bool intersectsWithRay(const Ray& ray);

    private:
        Vector center_;
        int radius_;

        float findIntersection(const Ray& ray);
};

}  // namespace geometry

#endif  // SPHERE_HPP
