#pragma once

#include <vector>
#include "Vector.h"
#include "Ray.h"
#include "Sphere.h"
#include "BVHAccel.h"

namespace Hybrid {
	class Scene {
	public:
		Scene() {}

		std::vector<std::shared_ptr<Shape>> CreateWorld() {
			{
				auto s = std::make_shared<Sphere>(Vector3(0.0f, 0.0f, 0.0f), 0.5f, Vector3(1.0f, 0.0f, 0.0f));
				m_Shapes.push_back(s);
			}

			{
				auto s = std::make_shared<Sphere>(Vector3(1.0f, 0.0f, 0.0f), 0.5f, Vector3(1.0f, 0.0f, 0.0f));
				m_Shapes.push_back(s);

			}
			std::vector<std::shared_ptr<Shape>> wrapper;
			
			wrapper.push_back(std::make_shared<BVHNode>(m_Shapes, 0.0, 1.0));

			return wrapper;
		}

		std::vector<std::shared_ptr<Shape>> GetAllPrimitives();

		bool BoundingBoxForAllPrimitives(Bounds3& createdBoundingBox) const;
	private:
		std::vector<std::shared_ptr<Shape>> m_Shapes;
	};

	inline std::ostream& operator<<(std::ostream& out, const Sphere& s) {
		out << "Origin: " << s.GetOrigin() << "Radius: " << s.GetRadius() << std::endl;

		return out;
	}
}