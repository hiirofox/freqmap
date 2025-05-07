#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

class MapFunc
{
private:
	float starty = 0.0, endy = 1.0;
	float sina = 0, sinfreq = 0, sint = 0, sindt = 0;
public:
	float operator ()(float x)
	{
		float y1 = x * (endy - starty) + starty;
		float y2 = sinf((x * sinfreq + sint) * 2.0 * M_PI) * sina;
		return y1 + y2;
	}
	void Updata()
	{
		sint += sindt;
	}
	void SetStartEnd(float start, float end)
	{
		starty = start;
		endy = end;
	}
	void SetSinParam(float sina, float sinfreq, float sindt)
	{
		this->sina = sina;
		this->sinfreq = sinfreq;
		this->sindt = sindt;
	}
};