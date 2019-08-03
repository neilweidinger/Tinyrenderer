#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <ostream>

namespace geometry {

class Vector {
    public:
        Vector();
        Vector(uint8_t r, uint8_t g, uint8_t b);
        friend std::ostream& operator<<(std::ostream& os, const Vector& vec);

    private:
        uint8_t r_val_;
        uint8_t g_val_;
        uint8_t b_val_;
};

}  // namespace geometry

#endif  // GEOMETRY_HPP
