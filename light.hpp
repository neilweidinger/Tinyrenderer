#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "vector.hpp"

namespace lighting {

class Light {
    public:
        Light(float intensity, const geometry::Vector& direction);

    private:
        float intensity_;
        geometry::Vector direction_;
};

}  // namespace lighting

#endif  // LIGHT_HPP
