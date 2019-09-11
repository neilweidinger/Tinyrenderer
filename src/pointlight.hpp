#ifndef POINTLIGHT_HPP
#define POINTLIGHT_HPP

#include "light.hpp"
#include "vector.hpp"

namespace lighting {

class PointLight : public Light {
    public:
        PointLight(const geometry::Vector& position, float intensity);
        float getFalloff(const geometry::Vector& hit_point) const override;
        geometry::Vector getDirectionToLight(const geometry::Vector& hit_point) const override;

    private:
        geometry::Vector position_;
};

}  // namespace lighting

#endif  // POINTLIGHT_HPP
