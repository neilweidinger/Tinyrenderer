#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <ostream>

namespace geometry {

class Vector {
    public:
        Vector(uint8_t x, uint8_t y, uint8_t z);
        int dotProduct(const Vector& vec) const;
        void scalarMultiply(int scalar);
        Vector scalarMultiply(int scalar) const;
        Vector& operator+=(const Vector& rhs);
        Vector& operator-=(const Vector& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Vector& vec);

    private:
        uint8_t x_val_;
        uint8_t y_val_;
        uint8_t z_val_;
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
