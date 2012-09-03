#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <iostream>

namespace CSS {

class Color {
public:
	float r, g, b, a;
	std::string color;
	
	Color(float r_, float g_, float b_)
	: r(r_), g(g_), b(b_) {}

	Color(unsigned int hex) 
	{
		r = ((hex >> 24) & 0xFF) / 255.0f;
		g = ((hex >> 16) & 0xFF) / 255.0f;
		b = ((hex >>  8) & 0xFF) / 255.0f;
		a = ((hex >>  0) & 0xFF) / 255.0f;
	}

	Color(std::string color_) : color(color_)
	{
	}
};

}; /* namespace */


#endif /* __COLOR_HPP__ */
