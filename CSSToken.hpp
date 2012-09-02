#ifndef __TOKEN_HPP__
#define __TOKEN_HPP__

#include <iostream>

namespace CSS {

/* selector { property: value; } */

typedef enum {	TokenSelector, 			/* x {} */

		TokenDeclarationBegin;		/* { 	*/
		TokenDeclarationEnd;		/* } 	*/
		TokenDeclarationProperty, 	/* x:   */
		TokenDeclarationValue,		/*  :x 	*/
		TokenDeclarationColon,		/*  :  	*/
		TokenDeclarationSemicolon,	/*    ; */

		TokenCommentBegin,		/*      */
		TokenCommentEnd,		/* 	*/
	} TokenType;

class Token {
public:
	TokenType   type;
	std::string text;
	
	Token(TokenType type_, std::string text_)
	: type(type_), text(text_) {}
};


}; /* namespace */


#endif /* __TOKEN_HPP__ */
