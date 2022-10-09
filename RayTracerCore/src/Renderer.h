#pragma once
#include "Scene.h"
#include <iostream>

namespace Hybrid {
	class Renderer {
	public:
		//uint32_t GetColorAt(const Vector2& coord);
		uint32_t GetColorAt(const Vector3& direction);
		void Render(int width, int height, uint32_t* buffer);

		Renderer() {
			m_Scene = new Scene();
		}

		~Renderer() {
			delete m_Scene;
		}
	public:
		Scene* GetCurrentScene();
	private:
		Scene* m_Scene;
	};
}