#ifndef RAY_HPP
#define RAY_HPP

#include "vector.hpp"

namespace geometry {

class Ray {
    public:
        Ray(const geometry::Vector& origin, const geometry::Vector& direction);

    private:
        geometry::Vector origin_;
        geometry::Vector dir_;
};

}

#endif  // RAY_HPP
