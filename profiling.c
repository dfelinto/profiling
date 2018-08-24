#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "utils.h"

typedef enum {
	MODE_NONE = -1,
	MODE_PLANE = 0,
	MODE_MULTIPLICATION = 1,
} eModeType;

static bool arguments(int argc, char *argv[], eModeType *r_mode, int *r_num_loops) {
	for (int i = 1; i < argc; i++) {
		const char *arg = argv[i];
		if (strcmp(arg, "plane") == 0) {
			*r_mode = MODE_PLANE;
		}
		else if (strcmp(arg, "multiplication") == 0) {
			*r_mode = MODE_MULTIPLICATION;
		}
		else {
			*r_num_loops = atoi(arg);
			if ((*r_num_loops) < 1) {
					*r_mode = MODE_NONE;
					break;
			}
		}
	}

	if (*r_mode == MODE_NONE) {
		printf("Expected: %s [plane|multiplication] [loops]\n", argv[0]);
		return false;
	}

	return true;
}

static void run_plane_routines(const int num_loops)
{
	float pt[3] = {2.0f, 1.0f, 3.7f};
	float plane[4] = {0.0f, 1.0f, 2.0f, 3.0f};

	for (int i = 0; i < num_loops; i++) {
		float dist = dist_signed_squared_to_plane_v3(pt, plane);
	}
}

static void run_multiplication_routines(const int num_loops)
{
	float vec[3] = {1.0f, 2.0f, 3.0f};
	float mat[4][4] = {
		{1.0f, 0.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f, 0.0f},
		{0.0f, 0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 0.0f, 0.0f},
	};
	float r[3];

	for (int i = 0; i < num_loops; i++) {
		mul_v3_m4v3(r, mat, vec);
	}
}

int main(int argc, char *argv[]) {
	eModeType mode = MODE_NONE;
	int num_loops = 1000;

	if (!arguments(argc, argv, &mode, &num_loops)) {
		return 1;
	}

	switch (mode) {
		case MODE_PLANE:
			run_plane_routines(num_loops);
			break;
		case MODE_MULTIPLICATION:
			run_multiplication_routines(num_loops);
			break;
		case MODE_NONE:
			assert(!"It shouldn't happen!\n");
			return 1;
		default:
			break;
	}

	return 0;
}
