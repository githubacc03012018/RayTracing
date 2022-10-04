#pragma once
#include <ostream>
namespace Hybrid {
	class Vector2 {
	public:
		float operator[] (int i) const {
			if (i >= 0 && i < 2) {
				if (i == 0) return x;
				if (i == 1) return y;
			}
		}
		
		Vector2(float x, float y) :
			x(x), y(y) {}
	public:
		float x, y = 0.0f;
	};

	class Vector3 : public Vector2 {
	public:
		float operator[] (int i) const {
			if (i >= 0 && i < 3) {
				if (i == 0) return x;
				if (i == 1) return y;
				if (i == 2) return z;
			}
		}

		Vector3(float x, float y, float z) :
			Vector2(x, y), z(z) {}

		//friend std::ostream& operator<<(std::ostream& os, const Vector3& vector);
	public:
		float z = 0.0f;
	};

	inline std::ostream& operator<<(std::ostream& out, const Vector3& s) {
		out << "x: " << s.x << " y: " << s.y << " z: " << s.z << std::endl;

		return out;
	}
}