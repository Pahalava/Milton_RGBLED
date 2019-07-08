/*
	Milton_RGB_Tools.h contains some pre-defined colours
	and tools to convert colours from one form to another;
	Like RGB to HSV or RGB to Hex etc.
*/

#include "Arduino.h"
#include "Milton_RGB_Tools.h"

#define FRACT(float x) ( x - int(x);)
#define MIX(float a, float b, float t) ( a + ( b - a ) * t ;)
#define STEP(float e, float x) ( x < e ? 0.0 : 1.0 ;)

Milton_RGB_Tools::Milton_RGB_Tools()
{}

RGB hex2rgb(unsigned long hex)
{
	_rgb.r = hex >> 16;
	_rgb.g = (hex & 0x00ff00) >> 8;
	_rgb.b = (hex & 0x0000ff);

	return _rgb;
}

unsigned long rgb2hex(RGB rgb)
{
	_hex |= rgb.r << 16;
	_hex |= rgb.g << 8;
	_hex |= rgb.b;

	return _hex;
}

HSV rgb2hsv(RGB rgb)
{
	int r = rgb.r;
	int g = rgb.g;
	int b = rgb.b;

	float s = STEP(b, g);
	float px = MIX(b, g, s);
	float py = MIX(g, b, s);
	float pz = MIX(-1.0, 0.0, s);
	float pw = MIX(0.6666666, -0.3333333, s);
	s = STEP(px, r);
	float qx = MIX(px, r, s);
	float qz = MIX(pw, pz, s);
	float qw = MIX(r, px, s);
	float d = qx - min(qw, py);

	_hsv.h = abs(qz + (qw - py) / (6.0 * d + 1e-10));
	_hsv.s = d / (qx + 1e-10);
	_hsv.v = qx;

	return _hsv;
}

RGB hsv2rgb(HSV hsv)
{
	float h = hsv.h;
	float s = hsv.s;
	float v = hsv.v;

	_rgb.r = v * MIX(1.0, constrain(abs(FRACT(h + 1.0) * 6.0 - 3.0) - 1.0, 0.0, 1.0), s);
	_rgb.g = v * MIX(1.0, constrain(abs(FRACT(h + 0.6666666) * 6.0 - 3.0) - 1.0, 0.0, 1.0), s);
	_rgb.b = v * MIX(1.0, constrain(abs(FRACT(h + 0.3333333) * 6.0 - 3.0) - 1.0, 0.0, 1.0), s);

	return _rgb;
}

unsigned long hsv2hex(HSV hsv)
{
	return rgb2hex ( hsv2rgb( hsv ) );
}

HSV hex2hsv(unsigned long hex)
{
	return rgb2hsv ( hex2rgb ( hex ) );
}
