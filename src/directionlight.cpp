#include "directionlight.hpp"

namespace lighting {

DirectionLight::DirectionLight(const geometry::Vector& direction, float intensity)
  : Light {intensity},
    direction_ {geometry::normalize(direction)}
{}

// direction lights don't have a falloff, so return 1
float DirectionLight::getFalloff(const geometry::Vector& hit_point) const {
    return 1.f;
}

geometry::Vector DirectionLight::getDirectionToLight(const geometry::Vector& hit_point) const {
    return geometry::scalarMultiply(-1, direction_);
}

}  // namespace lighting
