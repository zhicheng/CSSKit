#include "CSSLexer.hpp"

namespace CSS {

void
Lexer::consume()
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
	std::string identifier;

	while (isspace(c))
		consume();

	while (c != EOF) {
		switch (c) {
		case ';':
			consume();
			return new Token(TokenSEMICOLON, ";");
		case '{':
			consume();
			return new Token(TokenBLOCKOPEN, "{");
		case '}':
			consume();
			return new Token(TokenBLOCKCLOSE, "}");
		case ':':
			consume();
			return new Token(TokenCOLON, ":");
		case '.':
			consume();
			return new Token(TokenDOT, ".");
		case '\'':
		{
			std::string str;
			do {
				consume();
				if (c == '\\') {
					consume(); // eat '\'
					str += c;
					consume();
				} else if (c != '\'') {
					str += c;
				}
			} while (c != '\'');
			consume();
			return new Token(TokenSTRING, str);
		}
		default:
			if (isalpha(c) || c == '-' || c == '_') {
				std::string buf;
				do { 
					buf += c; consume(); 
				} while (isalnum(c) || c == '-' || c == '_');
				return new Token(TokenIDENT, buf);
				return identToken();
			} else if (isnumber(c)) {
				std::string num;
				for (int i = 0; i < 6 && isnumber(c); i++) {
					num += c;
					consume();
				}
				if (!isalpha(c))
					return new Token(TokenNUMBER, num);
				printf("invalid character number: %c\n", c);
			} else {
				printf("invalid character: %c\n", c);
			}
		}
	}
	return new Token(TokenEOF, "");
}

}; /* namespace */

