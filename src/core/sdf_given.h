#pragma once
#include "vec3.h"

// Given: signed distance to an origin-centred box with these half-sizes.
HD inline float sdf_box(vec3 p, vec3 half_size) {
    vec3 offset = abs(p) - half_size;
    float inside = min(max(offset.x, max(offset.y, offset.z)), 0.0f);
    return length(max(offset, 0)) + inside;
}

// Given: intersection is not needed by the scene in this lab.
HD inline float op_intersect(float a, float b) {
    return max(a, b);
}
