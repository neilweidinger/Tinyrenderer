#include "light.hpp"

namespace lighting {

Light::Light(const geometry::Vector& direction, float intensity)
  : intensity_ {intensity},
    direction_ {geometry::normalize(direction)}
{}

float Light::getIntensity() const {
    return intensity_;
}

geometry::Vector Light::getDirection() const {
    return direction_;
}

}  // namespace lighting
