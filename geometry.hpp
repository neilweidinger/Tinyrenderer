#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <ostream>

namespace geometry {

class Vector {
    public:
        Vector(double x, double y, double z);
        double getX() const;
        double getY() const;
        double getZ() const;
        int dotProduct(const Vector& vec) const;
        void scalarMultiply(int scalar);
        friend Vector scalarMultiply(int scalar, Vector vec);
        Vector& operator+=(const Vector& rhs);
        Vector& operator-=(const Vector& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Vector& vec);

    private:
        double x_val_;
        double y_val_;
        double z_val_;
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
