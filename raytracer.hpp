#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include <vector>
#include "geometry.hpp"

namespace raytracer {

class Raytracer {
    public:
        Raytracer(int width = 1000, int height = 1000, int fov = 90);
        void render();

    private:
        const int width_;
        const int height_;
        const int fov_;
        void writeToFile() const;
        std::vector<geometry::Vector> frame_buffer_;  // represents a vector of rgb vectors
};

uint8_t scaleTo256Bits(float f);

}  // namespace raytracer

#endif  // RAYTRACER_HPP
