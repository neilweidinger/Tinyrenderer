#include <fstream>
#include <iostream>
#include "raytracer.hpp"

namespace raytracer {

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
                                 geometry::Vector {scaleTo256Bits(i / static_cast<float>(width_)),
                                                   scaleTo256Bits(j / static_cast<float>(height_)),
                                                   0.2});
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

float scaleTo256Bits(float f) {
    return static_cast<uint8_t>(f * 255);
}

}  // namespace raytracer

int main(int argc, char* argv[]) {
    raytracer::Raytracer rt {};
    rt.render();

    geometry::Sphere s {geometry::Vector {0, 0, 10}, 5};
    std::cout << std::boolalpha << s.intersectsWithRay(geometry::Vector {1, 0, 6}) << "\n";
}
