#include "CSSLexer.hpp"

namespace CSS {

void
Lexer::nextChar()
{
	p++;
	if (p >= input.length()) 
		c = EOF;
	else 
		c = input[p];
}

Token *
Lexer::nextToken()
{
	/* remove white space */
	if (isspace(c))
		nextChar();

	while (c != EOF) {
		switch (c) {
		case ';':
			nextChar();
			return new Token(TokenSEMICOLON, ";");
		case '{':
			nextChar();
			return new Token(TokenLBRACES, "{");
		case '}':
			nextChar();
			return new Token(TokenRBRACES, "}");
		case ':':
			nextChar();
			return new Token(TokenCOLON, ":");
			nextChar();
		case '.':
			nextChar();
			return new Token(TokenDOT, ".");
		default:
			if (isalpha(c)) 
				return identToken();
			else
				std::cout<<"invalid character: "<<c<<std::endl;
		}
	}
	return new Token(TokenEOF, "EOF");
}

Token *
Lexer::identToken()
{
	std::string buf;
	do { buf += c; nextChar(); } while (isalpha(c));
	return new Token(TokenIDENT, buf);
}

}; /* namespace */

