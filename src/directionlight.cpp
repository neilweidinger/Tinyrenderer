#include "directionlight.hpp"

namespace lighting {

DirectionLight::DirectionLight(const geometry::Vector& direction, float intensity)
  : Light {intensity},
    direction_ {geometry::normalize(direction)}
{}

geometry::Vector DirectionLight::getDirection(const geometry::Vector& hit_point) const {
    return direction_;
}

}  // namespace lighting
