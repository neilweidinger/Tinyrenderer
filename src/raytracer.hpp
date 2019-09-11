#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include <vector>
#include "vector.hpp"
#include "ray.hpp"
#include "sphere.hpp"
#include "light.hpp"

namespace raytracer {

using geometry::Vector;
using geometry::Ray;

class Raytracer {
    public:
        Raytracer(int width = 1200, int height = 600, int fov = 60);
        void addSphere(const geometry::Sphere& sphere);
        void addLight(lighting::Light* light);
        void render();

    private:
        const int width_;
        const int height_;
        const int fov_;
        std::vector<Vector> frame_buffer_;  // represents a buffer of rgb vectors
        std::vector<geometry::Sphere> spheres_;
        std::vector<lighting::Light*> lights_;

        struct HitPointInfo {
            float intersection_param;
            Vector hit_point;
            Vector intersection_normal;
        };

        void writeToFile() const;
        Vector valueAtPixel(int pixel_x, int pixel_y) const;
        Ray castRay(int pixel_x, int pixel_y) const;
        bool hitSphere(const Ray& camera_ray, HitPointInfo& hit_point_info, float max_intersection_param) const;
        HitPointInfo findClosestIntersection(const Ray& camera_ray, float max_intersection_param) const;
        Vector calculateDiffuseColor(const Vector& intersection_normal, const Vector& hit_point) const;
        Vector calculateLerpColor(const Ray& camera_ray) const;
        bool objectInWayOfLight(const lighting::Light& light, const Vector& hit_point) const;
};

}  // namespace raytracer

#endif  // RAYTRACER_HPP
