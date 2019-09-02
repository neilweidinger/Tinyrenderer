#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include <vector>
#include "vector.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "light.hpp"

namespace raytracer {

class Raytracer {
    public:
        Raytracer(int width = 1000, int height = 1000, int fov = 60);
        void render();
        void addSphere(const geometry::Sphere& sphere);
        void addLight(const lighting::Light& light);

    private:
        const int width_;
        const int height_;
        const int fov_;
        std::vector<geometry::Vector> frame_buffer_;  // represents a buffer of rgb vectors
        std::vector<geometry::Sphere> spheres_;
        std::vector<lighting::Light> lights_;

        void writeToFile() const;
        geometry::Vector color(int pixel_x, int pixel_y) const;
        geometry::Ray castRay(int pixel_x, int pixel_y) const;
        bool hitSphere(const geometry::Ray& camera_ray, geometry::Vector& intersection_normal) const;
};

}  // namespace raytracer

#endif  // RAYTRACER_HPP
