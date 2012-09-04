#ifndef __TOKEN_HPP__
#define __TOKEN_HPP__

#include <iostream>
#include <vector>

namespace CSS {

/* selector { property: value; } */

typedef enum {	TokenIDENT,			/* xxx  */
		TokenLBRACES,			/*  {   */
		TokenRBRACES,			/*  }   */
		TokenCOLON,			/*  :  	*/
		TokenDOT,			/*  .   */
		TokenNUM,			/* 123  */
		TokenSTRING,			/* 'xx' */
		TokenSEMICOLON,			/* ;	*/
		TokenEOF,			/* EOF  */
} TokenType;

static char tokenNames[9][12] = {
	"<IDENT>",
	"<LBRACES>",
	"<RBRACES>",
	"<COLON>",
	"<DOT>",
	"<NUM>",
	"<STRING>",
	"<SEMICOLON>",
	"<EOF>"
};

class Token {
public:
	TokenType   type;
	std::string text;
	
	Token(TokenType type_, std::string text_)
	: type(type_), text(text_) {}

	char *
	name()
	{
		return tokenNames[type];
	}
};


}; /* namespace */


#endif /* __TOKEN_HPP__ */
