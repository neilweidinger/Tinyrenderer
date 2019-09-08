#include "src/raytracer.hpp"
#include "src/sphere.hpp"
#include "src/directionlight.hpp"

int main(int argc, char* argv[]) {
    raytracer::Raytracer rt {};

    rt.addSphere(geometry::Sphere{geometry::Vector{4, -4, -20}, 5});
    rt.addSphere(geometry::Sphere{geometry::Vector{-5, 6, -15}, 5});

    // idk how we can't pass in dl as a temporary, need to find a fix
    lighting::DirectionLight dl {geometry::Vector{0, 0, -1}, 1.5};
    rt.addLight(&dl);

    rt.render();
}
