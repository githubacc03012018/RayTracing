#pragma once
#include <ostream>

#define MachineEpsilon (std::numeric_limits<float>::epsilon() * 0.5)

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

	class Vector3 {
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

		Vector3 operator- (const Vector3& other) const {
			return Vector3(x - other.x, y - other.y, z - other.z);
		}

		Vector3 operator* (const Vector3& other) const {
			return Vector3(x * other.x, y * other.y, z * other.z);
		}

		Vector3 operator/ (const float s) const {
			if (s != 0.0f) {
				auto inv = 1 / s;
				return Vector3(x * inv, y * inv, z * inv);
			}
		}

		Vector3() { x = y = z = 0.0f; }

		Vector3(float v) { x = y = z = v; }

		Vector3(float x, float y, float z) :
			x(x), y(y), z(z) {}

		float Length() const {
			return sqrt(x * x + y * y + z * z);
		}
		//friend std::ostream& operator<<(std::ostream& os, const Vector3& vector);
	public:
		float x;
		float y;
		float z;
	};

	using Point3 = Vector3; // Used for points

	inline std::ostream& operator<<(std::ostream& out, const Vector3& s) {
		out << "x: " << s.x << " y: " << s.y << " z: " << s.z << std::endl;

		return out;
	}

	inline Vector3 operator-(const float s, const Vector3 v) {
		return Vector3(s - v.x, s - v.y, s - v.z);
	}

	inline float Dot(const Vector3& v1, const Vector3& v2) {
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	inline Vector3 Normalize(const Vector3 v) {
		return v / v.Length();
	}

	inline float gamma(int n) {
		return (n * MachineEpsilon) / (1 - n * MachineEpsilon);
	}

	inline float Clamp(float val, float low, float high) {
		if (val < low) return low;
		if (val > high) return high;

		return val;
	}
}