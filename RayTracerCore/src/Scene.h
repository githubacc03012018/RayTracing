#pragma once

#include <vector>
#include "Vector.h"
#include "Ray.h"

namespace Hybrid {

	class Shape {};

	class Sphere : public Shape {
	public:
		Sphere(Vector3 origin, float radius) :
			m_Origin(origin), m_Radius(radius)
		{}

		bool Intersect(const Ray& ray) {
			float a = Dot(ray.GetDirection(), ray.GetDirection());
			float b = 2.0f * Dot(ray.GetOrigin(), ray.GetDirection());
			float c = Dot(ray.GetOrigin(), ray.GetOrigin()) - m_Radius * m_Radius;

			// Solve quadratic equation
			float discriminant = b * b - 4 * a * c;
			
			return discriminant >= 0.0f;

			//return true;
		}

		Vector3 GetOrigin() const {
			return m_Origin;
		}

		float GetRadius() const {
			return m_Radius;
		}
		//friend std::ostream& operator<<(std::ostream& os, const Sphere& sphere);
	private:
		Vector3 m_Origin;
		float m_Radius = 0.0f;
	};
	class Scene {
	public:
		Scene() {
			{
				Sphere s(Vector3(0.0f, 0.0f, 0.0f), 0.5f);
				m_Shapes.push_back(s);
			}
		}

		std::vector<Sphere> GetAllPrimitives();
	private:
		std::vector<Sphere> m_Shapes;
	};

	inline std::ostream& operator<<(std::ostream& out, const Sphere& s) {
		out << "Origin: " << s.GetOrigin() << "Radius: " << s.GetRadius() << std::endl;

		return out;
	}
}