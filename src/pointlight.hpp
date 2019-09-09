#ifndef POINTLIGHT_HPP
#define POINTLIGHT_HPP

#include "light.hpp"
#include "vector.hpp"

namespace lighting {

class PointLight : public Light {
    public:
        PointLight(const geometry::Vector& position, float intensity);
        geometry::Vector getDirection(const geometry::Vector& hit_point) const override;

    private:
        geometry::Vector position_;
};

}  // namespace lighting

#endif  // POINTLIGHT_HPP
