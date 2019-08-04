#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <ostream>

namespace geometry {

class Vector {
    public:
        Vector(uint8_t r, uint8_t g, uint8_t b);
        int dotProduct(Vector vec);
        Vector scalarMultiply(int scalar);
        friend std::ostream& operator<<(std::ostream& os, Vector vec);

    private:
        uint8_t r_val_;
        uint8_t g_val_;
        uint8_t b_val_;
};

class Sphere {
    public:
        Sphere(Vector center, int radius);
        bool intersectsWithRay(Vector ray);

    private:
        Vector center_;
        int radius_;
};

}  // namespace geometry

#endif  // GEOMETRY_HPP
