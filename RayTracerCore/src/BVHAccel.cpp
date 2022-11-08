#include "BVHAccel.h"
#include "Sphere.h"


namespace Hybrid {
	BVHNode::BVHNode(const std::vector<std::shared_ptr<Shape>>& world, int start, int end) {
		// build the structure recursively
		size_t objectSpan = end - start;
		auto objs = world;

		if (objectSpan == 1) {
			left = right = objs[start];
		}
		else if (objectSpan == 2) {
			left = objs[start];
			right = objs[start + 1];
		}
		else {
			auto mid = start + objectSpan/ 2;
			left = std::make_shared<BVHNode>(objs, start, mid);
			right = std::make_shared<BVHNode>(objs, mid, end);
		}

		Bounds3 leftBox = left->ObjectBound();
		Bounds3 rightBox = right->ObjectBound();

		box = SurroundingBox(leftBox, rightBox);
	}

	bool BVHNode::Intersects(const Ray& ray, float tMax, float& t) const {
		bool intersects = false;

		float min, max = 0.0f;
		/*if (box.Intersects(ray, &min, &max)) {

			auto leftHit = left->Intersects(ray, max, t);
			auto rightHit = right->Intersects(ray, leftHit ? t : max, t);

			intersects = leftHit || rightHit;
			return intersects;
		}*/

		auto leftHit = left->Intersects(ray, max, t);
		auto rightHit = right->Intersects(ray, leftHit ? t : max, t);

		intersects = leftHit || rightHit;

		return intersects;
	}

	Bounds3 BVHNode::ObjectBound() const {
		return box;
	}
}