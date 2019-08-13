#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include <vector>
#include "vector.hpp"
#include "ray.hpp"

namespace raytracer {

class Raytracer {
    public:
        Raytracer(int width = 1000, int height = 1000, int fov = 90);
        void render();

    private:
        const int width_;
        const int height_;
        const int fov_;
        std::vector<geometry::Vector> frame_buffer_;  // represents a buffer of rgb vectors

        void writeToFile() const;
        geometry::Vector color(int pixel_x, int pixel_y) const;
        geometry::Ray castRay(int pixel_x, int pixel_y) const;
};

float scaleTo256Bits(float f);

}  // namespace raytracer

#endif  // RAYTRACER_HPP
