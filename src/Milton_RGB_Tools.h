/*
	Milton_RGB_Tools.h contains some pre-defined colours
	and tools to convert colours from one form to another;
	Like RGB to HSV or RGB to Hex etc.
*/

#ifndef Milton_RGB_Tools_h
#define Milton_RGB_Tools_h

#define black	#000000
#define white	#FFFFFF
#define red	#FF0000
#define lime	#00FF00
#define blue	#0000FF
#define yellow	#FFFF00
#define cyan	#00FFFF
#define magenta	#FF00FF
#define silver	#C0C0C0
#define gray	#808080
#define maroon	#800000
#define olive	#808000
#define green	#008000
#define purple	#800080
#define teal	#008080
#define navy	#000080
#define crimson	#DC143C
#define orange	#FFA500
#define khaki	#F0E68C
#define olive	#808000
#define seagreen	#2E8B57
#define teal	#008080
#define turquoise	#40E0D0
#define steelblue	#4682B4
#define royalblue	#4169E1
#define indigo	#4B0082
#define violet	#EE82EE
#define chocolate	#D2691E

typedef struct
{
	byte r;
	byte g;
	byte b;
} RGB, *pRGB;

typedef struct
{
	float h;
	float s;
	float v;
} HSV, *pHSV;

class Milton_RGB_Tools
{
	public:
		Milton_RGB_Tools();
		RGB hex2rgb(unsigned long hex);
		unsigned long rgb2hex(RGB rgb);
		HSV rgb2hsv(RGB rgb);
		RGB hsv2rgb(HSV hsv);
		unsigned long hsv2hex(HSV hsv);
		HSV hex2hsv(unsigned long hex);
	private:
		unsigned long _hex;
		rgb _rgb;
		hsv _hsv;
		
};

#endif