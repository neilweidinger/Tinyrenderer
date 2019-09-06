#include "src/raytracer.hpp"

int main(int argc, char* argv[]) {
    raytracer::Raytracer rt {};

    rt.addSphere(geometry::Sphere{geometry::Vector{4, -4, -20}, 5});
    rt.addSphere(geometry::Sphere{geometry::Vector{-5, 6, -15}, 5});
    rt.addLight(lighting::Light{geometry::Vector{0, 0, -1}, 1.5});

    rt.render();
}
