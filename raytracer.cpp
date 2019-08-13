#include <fstream>
#include <iostream>
#include <cmath>
#include "raytracer.hpp"

namespace raytracer {

using geometry::Vector;
using geometry::Ray;

Raytracer::Raytracer(int width, int height, int fov)
  : width_ {width},
    height_ {height},
    fov_ {fov},
    frame_buffer_ {} {
        frame_buffer_.reserve(width_ * height_);
}

void Raytracer::render() {
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            frame_buffer_.insert(frame_buffer_.begin() + ((i * width_) + j),
                                 color(j, i));
        }
    }

    writeToFile();
}

void Raytracer::writeToFile() const {
    std::ofstream ofs {"./pic.ppm", std::ostream::binary};
    ofs << "P6\n" << width_ << " " << height_ << "\n" << 255 << "\n";

    for (int i = 0; i < frame_buffer_.size(); i++) {
        uint8_t r = static_cast<uint8_t>(frame_buffer_[i].getX());
        uint8_t g = static_cast<uint8_t>(frame_buffer_[i].getY());
        uint8_t b = static_cast<uint8_t>(frame_buffer_[i].getZ());
        ofs << r << g << b;
    }

    ofs.close();
}

Vector Raytracer::color(int pixel_x, int pixel_y) const {
    Vector unit_direction_ray = castRay(pixel_x, pixel_y).getDir();  // dir automatically normalized in ray ctor
    float intensity = 0.5 * (unit_direction_ray.getY() + 1);  // scale to [0, 1]

    // lerp between white and light blue
    Vector white = Vector {255, 255, 255};
    Vector blue = Vector {127, 178, 255};

    white.scalarMultiply(1 - intensity);
    blue.scalarMultiply(intensity);

    return white + blue;
}

Ray Raytracer::castRay(int pixel_x, int pixel_y) const {
    float ndc_x = (pixel_x + 0.5) / width_;
    float ndc_y = (pixel_y + 0.5) / height_;

    float aspect_ratio = width_ / height_;

    float world_x = (2 * ndc_x - 1) * std::tan(fov_ / 2 * M_PI / 180) * aspect_ratio;
    float world_y = (1 - 2 * ndc_y) * std::tan(fov_ / 2 * M_PI / 180);

    return Ray {Vector {0, 0, 0}, Vector {world_x, world_y, -1}};
}

float scaleTo256Bits(float f) {
    return static_cast<uint8_t>(f * 255);
}

}  // namespace raytracer

int main(int argc, char* argv[]) {
    raytracer::Raytracer rt {};
    rt.render();

    /* geometry::Sphere s {Vector {0, 0, 10}, 5}; */
    /* std::cout << std::boolalpha << s.intersectsWithRay(Vector {1, 0, 6}) << "\n"; */
}
