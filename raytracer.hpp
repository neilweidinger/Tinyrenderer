#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

namespace raytracer {

class Raytracer {
    public:
        void render();

    private:
        static constexpr int width = 1000;
        static constexpr int height = 1000;
};

uint8_t scaleTo256Bits(float f);

}  // namespace raytracer

#endif  // RAYTRACER_HPP
