#include "directionlight.hpp"

namespace lighting {

DirectionLight::DirectionLight(const geometry::Vector& direction, float intensity)
  : Light {intensity},
    direction_ {geometry::normalize(direction)}
{}

geometry::Vector DirectionLight::getDirectionToLight(const geometry::Vector& hit_point) const {
    return geometry::scalarMultiply(-1, direction_);
}

}  // namespace lighting
