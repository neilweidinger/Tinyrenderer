#ifndef RAY_HPP
#define RAY_HPP

#include "vector.hpp"

namespace geometry {

class Ray {
    public:
        Ray(const Vector& origin, const Vector& direction);
        Vector getOrigin() const;
        Vector getDirection() const;
        Vector pointAtParameter(float t) const;

    private:
        Vector origin_;
        Vector dir_;
};

}

#endif  // RAY_HPP
