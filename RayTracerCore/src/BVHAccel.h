#pragma once
#include "Sphere.h"
#include <vector>

namespace Hybrid {
	class BVHNode : public Shape {
	public:
		BVHNode(const std::vector<std::shared_ptr<Shape>>& world, int start, int end); // world should be vector<shape>
		BVHNode();

		bool Intersects(const Ray& ray, float tMax, float& t) const override;
		Bounds3 ObjectBound() const override;
		Vector3 GetOrigin() const override {
			return Vector3();
		}
	private:
		Bounds3 box;
		std::shared_ptr<Shape> left;
		std::shared_ptr<Shape> right;
	};
}