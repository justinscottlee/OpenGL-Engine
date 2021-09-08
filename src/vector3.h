#ifndef VECTOR3_H_
#define VECTOR3_H_
#include <iostream>

struct Vector3 {
    float x, y, z;
    Vector3() : x(0), y(0), z(0) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    inline float operator*(const Vector3& rhs) { return x * rhs.x + y * rhs.y + z * rhs.z; }
    inline Vector3 operator+(const Vector3& rhs) { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
    inline Vector3& operator+=(const Vector3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
    inline Vector3 operator-(const Vector3& rhs) { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
    inline Vector3& operator-=(const Vector3& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; }
    inline Vector3 operator*(const float rhs) { return Vector3(x * rhs, y * rhs, z * rhs); }
    inline Vector3& operator*=(const float rhs) { x *= rhs; y *= rhs; z *= rhs; return *this; }
    inline Vector3 operator/(const float rhs) { return Vector3(x / rhs, y / rhs, z / rhs); }
    inline Vector3& operator/=(const float rhs) { x /= rhs; y /= rhs; z /= rhs; return *this; }
    inline Vector3& operator=(const Vector3& rhs) { x = rhs.x; y = rhs.y; z = rhs.z; return *this; }
    friend Vector3 operator*(const float lhs, const Vector3& rhs);
    friend std::ostream& operator<<(std::ostream& lhs, const Vector3& rhs);
};

inline Vector3 operator*(const float lhs, const Vector3& rhs) { return Vector3(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs); }
inline std::ostream& operator<<(std::ostream& lhs, const Vector3& rhs) { lhs << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")"; return lhs; }
#endif