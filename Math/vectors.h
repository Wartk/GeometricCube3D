//Vectors header developed by wartk(08/23/2024)

#ifndef VECTORS_H
#define VECTORS_H

typedef struct vector2{
	float x, y;
}Vector2;

typedef struct vector3{
	float x, y, z;

	vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
} Vector3;

struct VectorS{

	Vector3 add(Vector3 a, Vector3 b){
		Vector3 c;
		c.x = b.x + a.x;
		c.y = b.y + a.y;
		c.z = b.z + a.z;
		return c;
	}

};

struct VectorS Vectors;

#endif
