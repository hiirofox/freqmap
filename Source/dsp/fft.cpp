#include "fft.h"

#define M_PI 3.1415926535897932384626

/*
void fft_f32(complex_f32_t* a, int n, int inv)
{
	for (int i = 1, j = 0; i < n - 1; ++i)
	{
		for (int s = n; j ^= s >>= 1, ~j & s;)
			;
		if (i < j)
		{
			complex_f32_t tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	complex_f32_t t;
	int p1, p2;
	for (int m = 2; m <= n; m <<= 1)
	{
		complex_f32_t wm = complex_f32_t{ (float)cosf(2.0 * M_PI / m), (float)sinf(2.0 * M_PI / m) * inv };
		for (int k = 0; k < n; k += m)
		{
			complex_f32_t w = complex_f32_t{ 1.0, 0 };
			p1 = m >> 1;
			for (int j = 0; j < p1; ++j, w = cmul(w, wm))
			{
				p2 = k + j;
				t = cmul(w, a[p2 + p1]);
				a[p2 + p1] = csub(a[p2], t);
				a[p2] = cadd(a[p2], t);
			}
		}
	}
}*/

void fft_f32(float* are, float* aim, int n, int inv)
{
	for (int i = 1, j = 0; i < n - 1; ++i)
	{
		for (int s = n; j ^= s >>= 1, ~j & s;)
			;
		if (i < j)
		{
			float tmp = are[i];
			are[i] = are[j];
			are[j] = tmp;
			tmp = aim[i];
			aim[i] = aim[j];
			aim[j] = tmp;
		}
	}

	int p1, p2;
	for (int m = 2; m <= n; m <<= 1)
	{
		float wm_re = cosf(2.0f * M_PI / m);
		float wm_im = sinf(2.0f * M_PI / m) * -inv;

		for (int k = 0; k < n; k += m)
		{
			float w_re = 1.0f;
			float w_im = 0.0f;
			p1 = m >> 1;

			for (int j = 0; j < p1; ++j)
			{
				p2 = k + j;
				// 计算 t = w * a[p2 + p1]
				float t_re = w_re * are[p2 + p1] - w_im * aim[p2 + p1];
				float t_im = w_re * aim[p2 + p1] + w_im * are[p2 + p1];

				// 更新 a[p2] 和 a[p2 + p1]
				are[p2 + p1] = are[p2] - t_re;
				aim[p2 + p1] = aim[p2] - t_im;
				are[p2] += t_re;
				aim[p2] += t_im;

				// 更新 w = w * wm
				t_re = w_re * wm_re - w_im * wm_im;
				t_im = w_re * wm_im + w_im * wm_re;
				w_re = t_re;
				w_im = t_im;
			}
		}
	}
}