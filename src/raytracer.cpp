#include <fstream>
#include <cmath>
#include <limits>
#include "raytracer.hpp"

namespace raytracer {

Raytracer::Raytracer(int width, int height, int fov)
  : width_ {width},
    height_ {height},
    fov_ {fov},
    frame_buffer_ {} {
        frame_buffer_.reserve(width_ * height_);
}

void Raytracer::addSphere(const geometry::Sphere& sphere) {
    spheres_.push_back(sphere);
}

void Raytracer::addLight(lighting::Light* light) {
    lights_.push_back(light);
}

void Raytracer::render() {
    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < width_; j++) {
            frame_buffer_.insert(frame_buffer_.begin() + ((i * width_) + j), valueAtPixel(j, i));
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

Vector Raytracer::valueAtPixel(int pixel_x, int pixel_y) const {
    Ray camera_ray = castRay(pixel_x, pixel_y);
    HitPointInfo hit_object_info;

    if (hitSphere(camera_ray, hit_object_info, std::numeric_limits<float>::max())) {
        return calculateDiffuseColor(hit_object_info.intersection_normal, hit_object_info.hit_point);
    }

    return calculateLerpColor(camera_ray);
}

Ray Raytracer::castRay(int pixel_x, int pixel_y) const {
    float ndc_x = (pixel_x + 0.5) / width_;
    float ndc_y = (pixel_y + 0.5) / height_;

    float aspect_ratio = static_cast<float>(width_) / height_;  // cast to avoid int division

    float world_x = (2 * ndc_x - 1) * std::tan(fov_ / 2 * M_PI / 180) * aspect_ratio;
    float world_y = (1 - 2 * ndc_y) * std::tan(fov_ / 2 * M_PI / 180);

    return Ray {Vector {0, 0, 0}, Vector {world_x, world_y, -1}};
}

bool Raytracer::hitSphere(const Ray& camera_ray, HitPointInfo& hit_point_info, float max_intersection_param) const {
    HitPointInfo closest_hit_object = findClosestIntersection(camera_ray, max_intersection_param);
    if (closest_hit_object.intersection_param == max_intersection_param) return false;  // ray didn't hit anything

    hit_point_info = closest_hit_object;
    return true;
}

Raytracer::HitPointInfo Raytracer::findClosestIntersection(const Ray& camera_ray, float max_intersection_param) const {
    HitPointInfo temp_hpi {max_intersection_param};

    for (geometry::Sphere sphere : spheres_) {
        float temp_intersection_param = sphere.findIntersection(camera_ray);

        // currently we calculate hit_point and intersection_normal even if the sphere we're currently on
        // does not end up as the closest, might be a good spot to optimize away
        if (temp_intersection_param > 0 && temp_intersection_param < temp_hpi.intersection_param) {
            temp_hpi.intersection_param = temp_intersection_param;
            temp_hpi.hit_point = camera_ray.pointAtParameter(temp_hpi.intersection_param);
            temp_hpi.intersection_normal = geometry::normalize(temp_hpi.hit_point - sphere.getCenter());
        }
    }

    return temp_hpi;
}

Vector Raytracer::calculateDiffuseColor(const Vector& intersection_normal, const Vector& hit_point) const {
    float intensity = 0;

    for (lighting::Light* light : lights_) {
        if (objectInWayOfLight(*light, hit_point)) {
            continue;
        }

        Vector direction_to_light = light->getDirectionToLight(hit_point);
        float lambertian = std::max(0.f, intersection_normal.dotProduct(direction_to_light));

        intensity += (light->getIntensity() * lambertian) / light->getFalloff(hit_point);
    }

    return Vector {
        std::min(255.f, 120 * intensity),
        std::min(255.f, 0 * intensity),
        std::min(255.f, 100 * intensity)
    };
}

// linear interpolation of two colors for background
Vector Raytracer::calculateLerpColor(const Ray& camera_ray) const {
    Vector unit_direction_ray = camera_ray.getDirection();  // dir already normalized
    float intensity = 0.5 * (unit_direction_ray.getY() + 1);  // scale to [0, 1]

    Vector white = geometry::scalarMultiply(1 - intensity, Vector{255, 255, 255});
    Vector blue = geometry::scalarMultiply(intensity, Vector{127, 178, 255});

    return white + blue;
}

bool Raytracer::objectInWayOfLight(const lighting::Light& light, const Vector& hit_point) const {
    HitPointInfo unused_hpi;
    Vector direction_to_light = light.getDirectionToLight(hit_point);
    float distance_to_light = light.getDistanceToLight(hit_point);
    Ray ray_from_hit_point_to_light = Ray{hit_point, direction_to_light};

    return hitSphere(ray_from_hit_point_to_light, unused_hpi, distance_to_light);
}

}  // namespace raytracer
