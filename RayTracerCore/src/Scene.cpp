#include "Scene.h"

namespace Hybrid {
	std::vector<Sphere> Scene::GetAllPrimitives() {
		return m_Shapes;
	}

}