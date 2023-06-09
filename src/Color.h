#pragma once
#include "Ray.h"
#include "rtweekend.h"

void write_color(std::vector<unsigned char>& data, color pixel_color, std::size_t index, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide the color by the number of samples and gamma-correct for gamma=2.0.
    auto scale = 1.0 / samples_per_pixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);
    // Write the translated [0,255] value of each color component.
    data.at(index)     = CAST_UC(256 * clamp(r, 0.0, 0.999));
    data.at(index + 1) = CAST_UC(256 * clamp(g, 0.0, 0.999));
    data.at(index + 2) = CAST_UC(256 * clamp(b, 0.0, 0.999));
}
