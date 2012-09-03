#ifndef __COLOR_HPP__
#define __COLOR_HPP__

#include <iostream>

namespace CSS {

class Color {
public:
	float r, g, b;
	std::string color;
	
	Color(float r_, float g_, float b_)
	: r(r_), g(g_), b(b_) {}

	Color(unsigned int hex) 
	{
	}

	Color(std::string color_) : color(color_)
	{
	}
};

}; /* namespace */


#endif /* __COLOR_HPP__ */
