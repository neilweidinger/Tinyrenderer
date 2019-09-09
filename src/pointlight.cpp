#include "pointlight.hpp"

namespace lighting {

PointLight::PointLight(const geometry::Vector& position, float intensity)
  : Light {intensity},
    position_ {position}
{}

geometry::Vector PointLight::getDirectionToLight(const geometry::Vector& hit_point) const {
    return geometry::normalize(position_ - hit_point);
}

}  // namespace lighting
