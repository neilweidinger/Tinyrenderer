#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "vector.hpp"

namespace lighting {

class Light {
    public:
        Light(const geometry::Vector& direction, float intensity);
        float getIntensity() const;
        geometry::Vector getDirection() const;

    private:
        float intensity_;
        geometry::Vector direction_;
};

}  // namespace lighting

#endif  // LIGHT_HPP
