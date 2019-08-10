#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "vector.hpp"

namespace geometry {

class Sphere {
    public:
        Sphere(Vector center, int radius);
        bool intersectsWithRay(const Vector& ray);

    private:
        Vector center_;
        int radius_;
};

}  // namespace geometry

#endif  // SPHERE_HPP
