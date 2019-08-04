#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include <vector>
#include "geometry.hpp"

namespace raytracer {

class Raytracer {
    public:
        Raytracer(const int& width, const int& height);
        void render();

    private:
        const int width_;
        const int height_;
        void writeToFile() const;
        std::vector<geometry::Vector> frame_buffer_;
};

uint8_t scaleTo256Bits(float f);

}  // namespace raytracer

#endif  // RAYTRACER_HPP
