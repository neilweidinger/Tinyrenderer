#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <ostream>

namespace geometry {

class Vector {
    public:
        Vector(uint8_t r, uint8_t g, uint8_t b);
        int dotProduct(const Vector& vec) const;
        void scalarMultiply(int scalar);
        Vector scalarMultiply(int scalar) const;
        Vector& operator+=(const Vector& rhs);
        Vector& operator-=(const Vector& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Vector& vec);

    private:
        uint8_t r_val_;
        uint8_t g_val_;
        uint8_t b_val_;
};

double length(const Vector& vec);
Vector operator+(Vector lhs, const Vector& rhs);
Vector operator-(Vector lhs, const Vector& rhs);

class Sphere {
    public:
        Sphere(Vector center, int radius);
        bool intersectsWithRay(const Vector& ray);

    private:
        Vector center_;
        int radius_;
};

}  // namespace geometry

#endif  // GEOMETRY_HPP
