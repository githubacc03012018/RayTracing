#include <iostream>
#include "Renderer.h"
#include "Ray.h"

namespace Hybrid {
	void Renderer::Render(int viewportWidth, int viewportHeight, uint32_t* buffer) {
		for (int i = 0; i < viewportHeight; i++) {
			for (int j = 0; j < viewportWidth; j++) {
				auto u = (float)j / (float)viewportWidth;
				auto v = (float)i / (float)viewportHeight;
				Vector2 coord = { u,v };
				coord = coord * 2.0f - 1.0f;

				buffer[j + i * viewportWidth] = this->GetColorAt(coord);
			}
		}
	}

	uint32_t Renderer::GetColorAt(const Vector2& coord) {
		Vector3 finalColor(0, 0, 0);

		const Ray ray = Ray(Vector3(0.0f, 0.0f, -2.0f), Vector3(coord.x, coord.y, -1.0f));

		//Vector3 rayDirection = Vector3(x, y, -1.0f);

		for (size_t i = 0; i < m_Scene->GetAllPrimitives().size(); i++) {
			auto shape = m_Scene->GetAllPrimitives();
			if (shape[i].Intersect(ray)) {
				finalColor = Vector3(1, 0, 1);
			}
		}

		// use finalColor
		auto r = (uint8_t)(finalColor.x * 255.0f);
		auto g = (uint8_t)(finalColor.y * 255.0f);
		auto b = (uint8_t)(finalColor.z * 255.0f);

		return 0xff000000 | (b << 16) | (g << 8) | r;
	}

	Scene* Renderer::GetCurrentScene() {
		return m_Scene;
	}
}