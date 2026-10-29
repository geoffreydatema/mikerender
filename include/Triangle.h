#pragma once

#include "RenderObject.h"
#include "Ray.h"
#include "Interval.h"
#include "IntersectionRecord.h"
#include "Vector3.h"

class Triangle : public RenderObject {
    private:
        Vector3 vertex_a;
        Vector3 vertex_b;
        Vector3 vertex_c;

    public:
        Triangle(Vector3 a, Vector3 b, Vector3 c);
        void print();
        bool hit(const Ray& r, Interval ray_t, IntersectionRecord& rec) const override;
};
