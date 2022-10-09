#include "Scene.h"

namespace Hybrid {
	std::vector<Sphere> Scene::GetAllPrimitives() {
		return m_Shapes;
	}

	Bounds3 Scene::SurroundingBox(Bounds3& box0, Bounds3& box1) const {
		Point3 small(fmin(box0.pMin.x, box1.pMin.x),
			fmin(box0.pMin.y, box1.pMin.y),
			fmin(box0.pMin.z, box1.pMin.z));

		Point3 big(fmax(box0.pMax.x, box1.pMax.x),
			fmax(box0.pMax.y, box1.pMax.y),
			fmax(box0.pMax.z, box1.pMax.z));

		return Bounds3(small, big);
	}


	bool Scene::BoundingBoxForAllPrimitives(Bounds3& createdBoundingBox) const {
		if (m_Shapes.empty()) return false;

		bool isFirstBox = false;
		for (const auto& shape : m_Shapes) {
			auto tempBox = shape.ObjectBound();
			createdBoundingBox = isFirstBox ? tempBox : SurroundingBox(createdBoundingBox, tempBox);
			isFirstBox = false;
		}

		return true;
	}
}