#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include <iostream>

#include "CSSToken.hpp"

namespace CSS {

class Lexer {
public:
	std::string input;
	int p;
	int c;

	Lexer(std::string &input_)
	: input(input_), p(0)
	{
		c = input[p];
	}
	
	void consume();

	Token *nextToken();
};

}; /* namespace */


#endif /* __LEXER_HPP__ */

