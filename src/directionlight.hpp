#ifndef DIRECTIONLIGHT_HPP
#define DIRECTIONLIGHT_HPP

#include "light.hpp"
#include "vector.hpp"

namespace lighting {

class DirectionLight : public Light {
    public:
        DirectionLight(const geometry::Vector& direction, float intensity);
        float getFalloff(const geometry::Vector& hit_point) const override;
        geometry::Vector getDirectionToLight(const geometry::Vector& hit_point) const override;
        float getDistanceToLight(const geometry::Vector& hit_point) const override;

    private:
        geometry::Vector direction_;
};

}

#endif  // DIRECTIONLIGHT_HPP
