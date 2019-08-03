#include <array>
#include <algorithm>
#include <fstream>
#include "raytracer.hpp"
#include "geometry.hpp"

namespace raytracer {

void Raytracer::render() {
    std::array<geometry::Vector, Raytracer::height * Raytracer::width> frame_buffer;

    for (int i = 0; i < Raytracer::height; i++) {
        for (int j = 0; j < Raytracer::width; j++) {
            frame_buffer[(i * width) + j] = geometry::Vector {scaleTo256Bits(i / static_cast<float>(Raytracer::height)),
                                                              0,
                                                              scaleTo256Bits(j / static_cast<float>(Raytracer::width))};
        }
    }

    std::ofstream ofs {"./pic.ppm", std::ostream::binary};
    ofs << "P6\n" << Raytracer::width << " " << Raytracer::height << "\n" << 255 << "\n";

    for (int i = 0; i < frame_buffer.size(); i++) {
        ofs << frame_buffer[i];
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
