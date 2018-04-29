#pragma once

#include <cmath>

const double pi = 2 * acos(0.0);

// interpolation

// musicdsp.org hermite interpolation
inline float hermite(float x, float y0, float y1, float y2, float y3)
{
	// 4-point, 3rd-order Hermite (x-form) 
	float c0 = y1;
	float c1 = 0.5f * (y2 - y0);
	float c2 = y0 - 2.5f * y1 + 2.f * y2 - 0.5f * y3;
	float c3 = 1.5f * (y1 - y2) + 0.5f * (y3 - y0);
	return ((c3 * x + c2) * x + c1) * x + c0;
}

// random numbers

// https://stackoverflow.com/questions/1640258/need-a-fast-random-generator-for-c
static unsigned long x = 123456789, y = 362436069, z = 521288629;
inline unsigned long xorshift(void)
{
	unsigned long t;
	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;
	t = x;
	x = y;
	y = z;
	z = t ^ x ^ y;
	return z;
}

const double xorshiftMultiplier = 2.0 / ULONG_MAX;
inline double random()
{
	return -1.0 + xorshift() * xorshiftMultiplier;
}