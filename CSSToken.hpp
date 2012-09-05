#ifndef __TOKEN_HPP__
#define __TOKEN_HPP__

#include <iostream>
#include <vector>

namespace CSS {

/* define from 					  	*/
/* http://www.w3.org/TR/css3-syntax/#tokenization 	*/

/* selector { property: value; } */

typedef enum {	TokenIDENT,
		TokenATKEYWORD,
		TokenSTRING,
		TokenHASH,
		TokenNUMBER,
		TokenPERCENTAGE,
		TokenDIMENSION,
		TokenURI,
		TokenUNICODE_RANGE,
		TokenCDO,
		TokenCDE,
		TokenS,
		TokenCOMMENT,
		TokenFUNCTION,
		TokenINCLUDES,
		TokenDASHMATCH,
		TokenPREFIXMATCH,
		TokenSUFFIXMATCH,
		TokenSUBSTRINGMATCH,
		TokenCHAR,
		TokenBOM,
		
/* define for lexer */
		TokenBLOCKOPEN,
		TokenBLOCKCLOSE,
		TokenCOLON,
		TokenDOT,
		TokenSEMICOLON,
		TokenEOF,			/* EOF  */
} TokenType;

static char tokenNames[27][17] = {
	"<IDENT>",
	"<ATKEYWORD>",
	"<STRING>",
	"<HASH>",
	"<NUMBER>",
	"<PERCENTAGE>",
	"<DIMENSION>",
	"<URI>",
	"<UNICODE-RANGE>",
	"<CDO>",
	"<CDC>",
	"<S>",
	"<COMMENT>",
	"<FUNCTION>",
	"<INCLUDES>",
	"<DASHMATCH>",
	"<PREFIXMATCH>",
	"<SUFFIXMATCH>",
	"<SUBSTRINGMATCH>",
	"<CHAR>",
	"<BOM>",

	"<BLOCKOPEN>",
	"<BLOCKCLOSE>",
	"<COLON>",
	"<DOT>",
	"<SEMICOLON>",
	"<EOF>",
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
