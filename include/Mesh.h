#pragma once

#include <vector>
#include <cstdint>
#include "RenderObject.h"
#include "Ray.h"
#include "Interval.h"
#include "IntersectionRecord.h"
#include "Vector3.h"

using namespace std;

class Mesh : public RenderObject {
    private:
        vector<Vector3> vertices;
        vector<uint32_t> polygons;

    public:
        Mesh(vector<Vector3> v, vector<uint32_t> p);
        void print();
        bool get_intersection(const Ray& r, Interval ray_t, IntersectionRecord& rec) const override;
        bool intersect_triangle(const Ray& r, Interval ray_t, IntersectionRecord& rec, size_t i) const override;
};
