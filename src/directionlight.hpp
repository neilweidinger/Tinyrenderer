#ifndef DIRECTIONLIGHT_HPP
#define DIRECTIONLIGHT_HPP

#include "light.hpp"
#include "vector.hpp"

namespace lighting {

class DirectionLight : public Light {
    public:
        DirectionLight(const geometry::Vector& direction, float intensity);
        geometry::Vector getDirection() const override;

    private:
        geometry::Vector direction_;
};

}

#endif  // DIRECTIONLIGHT_HPP
