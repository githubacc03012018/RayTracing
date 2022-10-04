#pragma once
#include "Scene.h"
#include <iostream>

namespace Hybrid {
	class Renderer {
	public:
		uint32_t GetColorAt(float x, float y);
		void Render(int width, int height, uint32_t* buffer);

		Renderer() {
			m_Scene = new Scene();
			auto primitives = m_Scene->GetAllPrimitives();
			for (int i = 0; i < primitives.size(); i++) {
				auto current = primitives[i];
				std::cout << current << std::endl;
			}
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