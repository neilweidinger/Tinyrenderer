#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "vector.hpp"

namespace lighting {

class Light {
    public:
        Light(float intensity);
        virtual ~Light() {};
        float getIntensity() const;
        virtual float getFalloff(const geometry::Vector& hit_point) const = 0;
        virtual geometry::Vector getDirectionToLight(const geometry::Vector& hit_point) const = 0;

    protected:
        float intensity_;
};

}  // namespace lighting

#endif  // LIGHT_HPP
