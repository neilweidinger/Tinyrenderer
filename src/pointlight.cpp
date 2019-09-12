#include <cmath>
#include "pointlight.hpp"

namespace lighting {

PointLight::PointLight(const geometry::Vector& position, float intensity)
  : Light {intensity},
    position_ {position}
{}

float PointLight::getFalloff(const geometry::Vector& hit_point) const {
    geometry::Vector dtl = position_ - hit_point;
    /* return dtl.dotProduct(dtl); */
    return geometry::length(dtl);  // pretty sure my math is wrong here
}

geometry::Vector PointLight::getDirectionToLight(const geometry::Vector& hit_point) const {
    return geometry::normalize(position_ - hit_point);
}

float PointLight::getDistanceToLight(const geometry::Vector& hit_point) const {
    return geometry::length(position_ - hit_point);
}

}  // namespace lighting
