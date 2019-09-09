#include "src/raytracer.hpp"
#include "src/sphere.hpp"
#include "src/directionlight.hpp"
#include "src/pointlight.hpp"

int main(int argc, char* argv[]) {
    raytracer::Raytracer rt {};

    rt.addSphere(geometry::Sphere{geometry::Vector{4, -4, -20}, 5});
    rt.addSphere(geometry::Sphere{geometry::Vector{-5, 6, -15}, 5});

    // idk how to pass in lights as temporaries, need to find a fix
    lighting::DirectionLight dl {geometry::Vector{-1, -1, -1}, 1.5};
    rt.addLight(&dl);
    lighting::PointLight pl {geometry::Vector{0, -2, -10}, 1.5};
    rt.addLight(&pl);

    rt.render();
}
