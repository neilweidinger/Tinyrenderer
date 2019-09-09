#include "pointlight.hpp"

namespace lighting {

PointLight::PointLight(const geometry::Vector& position, float intensity)
  : Light {intensity},
    position_ {position}
{}

geometry::Vector PointLight::getDirection(const geometry::Vector& hit_point) const {
    return geometry::normalize(hit_point - position_);
}

}  // namespace lighting
