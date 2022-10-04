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
		
		Vector2 operator* (float scalar) const {
			return Vector2(scalar * x, scalar * y);
		}

		Vector2 operator- (const Vector2& other) const {
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator-(const float f) const {
			return Vector2(x - f, y - f);
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

		Vector3 operator* (float scalar) const {
			return Vector3(scalar * x, scalar * y, scalar * z);
		}

		Vector3 operator+ (const Vector3& other) const {
			return Vector3(x + other.x, y + other.y, z + other.z);
		}

		Vector3(float x) : Vector2(x,x), z(x) {}
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

	inline float Dot(const Vector3& v1, const Vector3& v2) {
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}
}