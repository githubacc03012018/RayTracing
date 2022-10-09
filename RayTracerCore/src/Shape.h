#pragma once
#include "Bounds.h"

namespace Hybrid {
	class Shape {
	public:
		virtual Bounds3 ObjectBound() const = 0;
		virtual bool Intersect(const Ray& ray, float& tMax, float& t) const = 0;
	};
}