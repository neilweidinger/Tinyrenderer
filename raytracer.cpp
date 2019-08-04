#include <fstream>
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
                                 geometry::Vector {scaleTo256Bits(i / static_cast<float>(height_)),
                                 0,
                                 scaleTo256Bits(j / static_cast<float>(width_))});
        }
    }

    writeToFile();
}

void Raytracer::writeToFile() const {
    std::ofstream ofs {"./pic.ppm", std::ostream::binary};
    ofs << "P6\n" << width_ << " " << height_ << "\n" << 255 << "\n";

    for (int i = 0; i < frame_buffer_.size(); i++) {
        ofs << frame_buffer_[i];
    }

    ofs.close();
}

uint8_t scaleTo256Bits(float f) {
    return static_cast<uint8_t>(f * 255);
}

}  // namespace raytracer

int main(int argc, char* argv[]) {
    raytracer::Raytracer rt {};
    rt.render();
}
