#pragma once
#include "Bounds.h"

namespace Hybrid {
	class Shape {
	public:
		virtual Vector3 GetOrigin() const = 0;
		virtual Bounds3 ObjectBound() const = 0;
		virtual bool Intersects(const Ray& ray, float tMax, float& t) const = 0;
	};
}