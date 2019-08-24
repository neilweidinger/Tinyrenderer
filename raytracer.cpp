#include <fstream>
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

void Raytracer::addSphere(geometry::Sphere sphere) {
    spheres_.push_back(sphere);
}

void Raytracer::render() {
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            frame_buffer_.insert(frame_buffer_.begin() + ((i * width_) + j), color(j, i));
        }
    }

    writeToFile();
}

void Raytracer::writeToFile() const {
    std::ofstream ofs {"./pic.ppm", std::ostream::binary};
    ofs << "P6\n" << width_ << " " << height_ << "\n" << 255 << "\n";

    for (uint32_t i = 0; i < frame_buffer_.size(); i++) {
        uint8_t r = static_cast<uint8_t>(frame_buffer_[i].getX());
        uint8_t g = static_cast<uint8_t>(frame_buffer_[i].getY());
        uint8_t b = static_cast<uint8_t>(frame_buffer_[i].getZ());
        ofs << r << g << b;
    }

    ofs.close();
}

Vector Raytracer::color(int pixel_x, int pixel_y) const {
    Ray camera_ray = castRay(pixel_x, pixel_y);
    Vector intersection_normal {};

    if (hitSphere(camera_ray, intersection_normal)) {
        return Vector {
                scaleTo256Bits((intersection_normal.getX() + 1) * 0.5),
                scaleTo256Bits((intersection_normal.getY() + 1) * 0.5),
                scaleTo256Bits((intersection_normal.getZ() + 1) * 0.5)};
    }

    Vector unit_direction_ray = camera_ray.getDir();  // dir already normalized in ray ctor above
    float intensity = 0.5 * (unit_direction_ray.getY() + 1);  // scale to [0, 1]

    Vector white = geometry::scalarMultiply(1 - intensity, Vector{255, 255, 255});
    Vector blue = geometry::scalarMultiply(intensity, Vector{127, 178, 255});

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

bool Raytracer::hitSphere(const Ray& camera_ray, Vector& intersection_normal) const {
    for (geometry::Sphere sphere : spheres_) {
        float intersection = sphere.findIntersection(camera_ray);

        if (intersection > 0) {
            intersection_normal = geometry::normalize(camera_ray.pointAtParameter(intersection) - sphere.getCenter());
            return true;
        }
    }

    return false;
}

float scaleTo256Bits(float f) {
    return static_cast<uint8_t>(f * 255);
}

}  // namespace raytracer

int main(int argc, char* argv[]) {
    raytracer::Raytracer rt {};
    rt.addSphere(geometry::Sphere{geometry::Vector{4, -4, -20}, 5});
    rt.addSphere(geometry::Sphere{geometry::Vector{-5, 6, -15}, 5});
    rt.render();
}
