#pragma once
#include "Shape.h"
#include "Vector.h"
#include "Ray.h"

namespace Hybrid {
	class Sphere : public Shape {
	public:
		Sphere(Vector3 origin, float radius, Vector3 color) :
			m_Origin(origin), m_Radius(radius), m_Color(color), zMin(Clamp(std::min(zMin, zMax), -radius, radius)),
			zMax(Clamp(std::max(zMin, zMax), -radius, radius))
		{}

		Vector3 GetOrigin() const override;

		float GetRadius() const {
			return m_Radius;
		}

		Bounds3 ObjectBound() const override;

		bool Intersects(const Ray& ray, float tMax, float& t) const override;

		Vector3 GetColor() const {
			return m_Color;
		}

	private:
		Vector3 m_Origin;
		Vector3 m_Color;
		const float m_Radius;
		const float zMin, zMax = 0.0f;
	};
}