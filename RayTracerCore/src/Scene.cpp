#include "Scene.h"

namespace Hybrid {
	std::vector<Sphere> Scene::GetAllPrimitives() {
		return m_Shapes;
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