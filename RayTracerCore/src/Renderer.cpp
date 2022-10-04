#include <iostream>
#include "Renderer.h"

namespace Hybrid {
	void Renderer::Render(int viewportWidth, int viewportHeight, uint32_t* buffer) {
		for (int i = 0; i < viewportHeight; i++) {
			for (int j = 0; j < viewportWidth; j++) {
				auto u = (float)j / (float)viewportWidth;
				auto v = (float)i / (float)viewportHeight;

				buffer[j + i * viewportWidth] = this->GetColorAt(u, v);
			}
		}
	}

	uint32_t Renderer::GetColorAt(float x, float y) {
		auto r = (uint8_t)(x * 255.0f);
		auto g = (uint8_t)(y * 255.0f);

		return 0xff000000 | (g << 8) | r;
	}

	Scene* Renderer::GetCurrentScene() {
		return m_Scene;
	}
}