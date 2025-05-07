#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include "../dsp/mapfunc.h"
#include <JuceHeader.h>

class DisplayMapFunc :public juce::Component
{
private:
	constexpr static int NumLines = 25;
	MapFunc* pMap = NULL;
	float lastys[NumLines][256] = { 0 };
public:
	DisplayMapFunc()
	{
	}
	void SetMapFunc(MapFunc* pMap)
	{
		this->pMap = pMap;
	}
	void paint(juce::Graphics& g) override
	{
		juce::Rectangle<int> rect = getBounds();
		int w = rect.getWidth(), h = rect.getHeight();

		g.setColour(juce::Colour(0x5500ff00));
		for (int n = 0; n < NumLines; ++n)//25¸ùÏß
		{
			float x = (float)n / NumLines;
			float y = 0;
			if (pMap)y = (*pMap)(x);

			for (int i = 1; i < 256; ++i)
			{
				g.drawLine((i - 1) * w / 256, h - lastys[n][i - 1] * h, (i) * w / 256, h - lastys[n][i] * h, 1.0);
				lastys[n][i - 1] = lastys[n][i];
			}
			lastys[n][255] = y;
		}

		g.setColour(juce::Colour(0xFF00FFFF));
		float lasty = 0;
		if (pMap)lasty = (*pMap)(0);
		for (int i = 1; i < 1024; ++i)
		{
			float x = (float)i / 1024.0;
			float y = 0;
			if (pMap)y = (*pMap)(x);
			g.drawLine((i - 1) * w / 1024.0, h - lasty * h, i * w / 1024.0, h - y * h, 2.5);
			lasty = y;
		}

		g.setColour(juce::Colour(0xFF00FF00));
		g.drawLine(0, 0, w, 0, 3);
		g.drawLine(0, 0, 0, h, 3);
		g.drawLine(w, 0, w, h, 3);
		g.drawLine(0, h, w, h, 3);
	}
};
