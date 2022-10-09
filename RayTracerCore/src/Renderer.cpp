#include <iostream>
#include "Renderer.h"
#include "Ray.h"

namespace Hybrid {
	const float PI = 3.1415f;
	void Renderer::Render(int viewportWidth, int viewportHeight, uint32_t* buffer) {

		/*auto h = tan(PI * 45 / 180);
		float aspectRatio = (float)(viewportWidth / viewportHeight);

		auto vpHeight = 2 * h;
		auto vpWidth = vpHeight * aspectRatio;*/
		auto horizontal = Vector3(2.0f, 0.0f, 0.0f);
		auto vertical = Vector3(0.0f, 2.0f, 0.0f);


		auto lower_left_corner = Vector3(0.0f, 0.0f, 0.0f) - horizontal / 2 - vertical / 2 - Vector3(0.0f, 0.0f, 1.0f);

		for (int i = 0; i < viewportHeight; i++) {
			for (int j = 0; j < viewportWidth; j++) {
				auto u = (float)j / (float)viewportWidth;
				auto v = (float)i / (float)viewportHeight;

				auto asd = lower_left_corner + horizontal * u + vertical * v;
				/*Vector2 coord = { u,v };
				coord = coord * 2.0f - 1.0f;*/

				buffer[j + i * viewportWidth] = this->GetColorAt(asd);
			}
		}
	}

	//uint32_t Renderer::GetColorAt(const Vector2& coord) {
	uint32_t Renderer::GetColorAt(const Vector3& direction) {
		Vector3 finalColor(0.1f, 0.1f, 0.2f);

		Vector3 origin = { 0.0f, 0.0f, -2.0f }; //camera origin
		//Vector3 direction = { coord.x, coord.y, -1.0f };

		const Ray ray = Ray(origin, direction);

		auto world = m_Scene->GetAllPrimitives();

		float maxDistance = std::numeric_limits<float>::max();
		float t = 0.0f;

		for (size_t i = 0; i < world.size(); i++) {
			const Sphere shape = world[i];

			if (shape.Intersect(ray, maxDistance, t)) {
				maxDistance = t;

				Vector3 lightPos = Vector3(1.0f, -1.0f, 1.0f);
				//xx + yy + zz = r2
				auto radius = lightPos.Length();
				auto lightDir = lightPos - ray.GetAt(t);

				lightDir = Normalize(lightDir);

				auto normal = Normalize(ray.GetAt(t) - shape.GetOrigin());
				auto cosLaw = std::max<float>(0.0f, Dot(lightDir, normal));
				auto area = 4 * PI * radius * radius;

				finalColor = Vector3(1.0f, 0.0f, 1.0f) * cosLaw / (area * 1 / 20);

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