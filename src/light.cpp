#include "light.hpp"

namespace lighting {

Light::Light(float intensity)
  : intensity_ {intensity}
{}

float Light::getIntensity() const {
    return intensity_;
}

}  // namespace lighting
