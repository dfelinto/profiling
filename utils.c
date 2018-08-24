#include <math.h>

#include "utils.h"

MINLINE float len_squared_v3(const float v[3])
{
	return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

MINLINE float dot_v3v3(const float a[3], const float b[3])
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

MINLINE float plane_point_side_v3(const float plane[4], const float co[3])
{
	return dot_v3v3(co, plane) + plane[3];
}

float dist_signed_squared_to_plane_v3(const float pt[3], const float plane[4])
{
	const float len_sq = plane[0] * plane[0] + plane[1] * plane[1] + plane[2] * plane[2];
	const float side = pt[0] * plane[0] + pt[1] * plane[1] + pt[2] * plane[2] + plane[3];
	const float fac = side / len_sq;
	return copysignf(len_sq * (fac * fac), side);
}

void mul_v3_m4v3(float r[3], const float mat[4][4], const float vec[3])
{
	const float x = vec[0];
	const float y = vec[1];

	r[0] = x * mat[0][0] + y * mat[1][0] + mat[2][0] * vec[2] + mat[3][0];
	r[1] = x * mat[0][1] + y * mat[1][1] + mat[2][1] * vec[2] + mat[3][1];
	r[2] = x * mat[0][2] + y * mat[1][2] + mat[2][2] * vec[2] + mat[3][2];
}
