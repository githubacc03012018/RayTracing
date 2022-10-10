#pragma once
#include "Sphere.h"
#include <vector>

namespace Hybrid {
	class BVHNode {
	public:
		BVHNode(const std::vector<Sphere>& world, int start, int end); // world should be vector<shape>

		~BVHNode() {
			/*delete left;
			delete right;*/
		}

		bool Intersects(const Ray& ray, float tMax, float t) const;
	private:
		std::shared_ptr<Sphere> left;
		std::shared_ptr<Sphere> right;

		//Sphere* left = nullptr;
		//Sphere* right = nullptr;
		Bounds3 box;
	};
}