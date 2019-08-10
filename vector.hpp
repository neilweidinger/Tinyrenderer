#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <ostream>

namespace geometry {

class Vector {
    public:
        Vector(float x, float y, float z);
        float getX() const;
        float getY() const;
        float getZ() const;
        int dotProduct(const Vector& vec) const;
        void scalarMultiply(int scalar);
        friend Vector scalarMultiply(int scalar, Vector vec);
        Vector& operator+=(const Vector& rhs);
        Vector& operator-=(const Vector& rhs);
        friend std::ostream& operator<<(std::ostream& os, const Vector& vec);

    private:
        float x_val_;
        float y_val_;
        float z_val_;
};

float length(const Vector& vec);
Vector operator+(Vector lhs, const Vector& rhs);
Vector operator-(Vector lhs, const Vector& rhs);

}  // namespace geometry

#endif  // VECTOR_HPP
