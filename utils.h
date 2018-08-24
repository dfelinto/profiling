
#ifndef UTILS_H
#define UTILS_H

#define MINLINE static inline

MINLINE float len_squared_v3(const float v[3]);
MINLINE float dot_v3v3(const float a[3], const float b[3]);
MINLINE float plane_point_side_v3(const float plane[4], const float co[3]);
float dist_signed_squared_to_plane_v3(const float pt[3], const float plane[4]);
void mul_v3_m4v3(float r[3], const float mat[4][4], const float vec[3]);

#endif /* UTILS_H */
