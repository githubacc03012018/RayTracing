#pragma once
#include "Ray.h"

namespace Hybrid {
	class Bounds3 {
	public:
		Bounds3() {
			auto minNum = std::numeric_limits<float>::lowest();
			auto maxNum = std::numeric_limits<float>::max();
			pMin = Point3(maxNum, maxNum, maxNum);
			pMax = Point3(minNum, minNum, minNum);
		}

		Bounds3(const Point3& p) : pMin(p), pMax(p) { }

		Bounds3(const Point3& p1, const Point3& p2)
			: pMin(std::min(p1.x, p2.x), std::min(p1.y, p2.y),
				std::min(p1.z, p2.z)),
			pMax(std::max(p1.x, p2.x), std::max(p1.y, p2.y),
				std::max(p1.z, p2.z)) {
		}

		bool Intersects(const Ray& ray, float* hitt0 = nullptr, float* hitt1 = nullptr) const;
	public:
		Point3 pMin, pMax;
	};


	inline bool Bounds3::Intersects(const Ray& ray, float* hitt0, float* hitt1) const {
		float min = 0, max = ray.tMax;
		for (int i = 0; i < 3; ++i) {
			float invRayDir = 1 / ray.GetDirection()[i];
			float tNear = (pMin[i] - ray.GetOrigin()[i]) * invRayDir;
			float tFar = (pMax[i] - ray.GetOrigin()[i]) * invRayDir;

			if (tNear > tFar) {
				std::swap(tNear, tFar);
			}

			min = tNear > min ? tNear : min;
			max = tFar < max ? tFar : max;
			if (min > max) return false;
		}

		if (hitt0) *hitt0 = min;
		if (hitt1) *hitt1 = max;

		return true;
	}
}