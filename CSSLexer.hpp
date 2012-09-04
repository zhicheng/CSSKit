#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include <iostream>

#include "CSSToken.hpp"

namespace CSS {

class Lexer {
public:
	std::string input;
	int p;
	char c;

	Lexer(std::string &input_)
	: input(input_), p(0)
	{
		c = input[p];
	}
	
	void nextChar();

	Token *nextToken();
	Token *identToken();
};

}; /* namespace */


#endif /* __LEXER_HPP__ */

