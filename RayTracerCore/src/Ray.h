#pragma once
#include "Vector.h"

namespace Hybrid {
	class Ray {
	public:
		Ray(Vector3 origin, Vector3 direction) : 
			m_Origin(origin), m_Direction(direction) {}

		Vector3 GetAt(float t) const {
			return m_Origin + m_Direction * t;
		}

		Vector3 GetOrigin() const {
			return m_Origin;
		}

		Vector3 GetDirection() const {
			return m_Direction;
		}

		float tMax = INFINITY;
	private:
		Vector3 m_Origin;
		Vector3 m_Direction;
	};
}