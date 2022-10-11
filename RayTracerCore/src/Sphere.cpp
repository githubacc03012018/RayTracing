#include "Sphere.h"

namespace Hybrid {
	Vector3 Sphere::GetOrigin() const {
		return m_Origin;
	}

	Bounds3 Sphere::ObjectBound() const {
		return Bounds3(m_Origin - Vector3(m_Radius, m_Radius, m_Radius),
						m_Origin + Vector3(m_Radius, m_Radius, m_Radius));
	}

	bool Sphere::Intersects(const Ray& ray, float tMax, float& t) const {

		const Vector3 origin = ray.GetOrigin() - m_Origin;
		float a = Dot(ray.GetDirection(), ray.GetDirection());
		float b = 2.0f * Dot(origin, ray.GetDirection());
		float c = Dot(origin, origin) - m_Radius * m_Radius;

		// Solve quadratic equation
		float discriminant = b * b - 4 * a * c;

		if (discriminant < 0.0f) {
			return false;
		}

		float closestT = (-b - sqrt(discriminant)) / (2.0f * a);
		if (closestT > tMax) {
			return false;
		}

		t = closestT;
		return true;
	}
}