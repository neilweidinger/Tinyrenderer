#include "light.hpp"

namespace lighting {

Light::Light(float intensity, const geometry::Vector& direction)
  : intensity_ {intensity},
    direction_ {direction}
{}

}  // namespace lighting
