#pragma once

#include <vector>
#include "Vector.h"
#include "Ray.h"
#include "Sphere.h"
#include "BVHAccel.h"

namespace Hybrid {
	class Scene {
	public:
		Scene() {
			{
				Sphere s(Vector3(0.0f, 0.0f, 0.0f), 0.5f, Vector3(1.0f, 0.0f, 0.0f));
				m_Shapes.push_back(s);
			}

			//auto 
			m_Structure = new BVHNode(m_Shapes, 0, m_Shapes.size());
			//
			

		}

		~Scene() {
			delete m_Structure;
		}

		std::vector<Sphere> GetAllPrimitives();

		bool BoundingBoxForAllPrimitives(Bounds3& createdBoundingBox) const;
		Bounds3 SurroundingBox(Bounds3& box0, Bounds3& box1) const;
	private:
		std::vector<Sphere> m_Shapes;
		BVHNode* m_Structure = nullptr;
	};

	inline std::ostream& operator<<(std::ostream& out, const Sphere& s) {
		out << "Origin: " << s.GetOrigin() << "Radius: " << s.GetRadius() << std::endl;

		return out;
	}
}