#include "BVHAccel.h"
#include "Sphere.h"

namespace Hybrid {
	//const std::vector<Sphere>& world should be vector<Shape>
	BVHNode::BVHNode(const std::vector<Sphere>& world, int start, int end) {
		// build the structure recursively
	}
	
	bool BVHNode::Intersects(const Ray& ray, float tMax, float t) const {
		bool intersects = false;

		float min, max = 0.0f;
		if (box.Intersects(ray, &min, &max)) {
		
			auto leftHit = left->Intersect(ray, max, t); 
			auto rightHit = right->Intersect(ray, leftHit ? t : max, t);

			intersects = leftHit || rightHit;
			return intersects;
		}

		return intersects;
	}
}